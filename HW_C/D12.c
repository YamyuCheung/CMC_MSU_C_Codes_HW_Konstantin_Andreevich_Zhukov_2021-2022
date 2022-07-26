//
//  D12.c
//  c
//
//  Created by Xinyu Zhang on 20/11/2021.
//
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永無BUG
//
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/errno.h>
#include <sys/wait.h>

//描述一串用'|'连接起来的命令中的一个，
struct CmdDescription{
    int cmdNameIndexInArgv;  //命令名在成熟的argv[]中的位置
    int lastCmdArgIndexInArgv; //命令的最后一个参数在程序的argv[]中的位置
};

//描述各个命令
struct CmdLineDescription{
    int cmd_num;
    struct CmdDescription *cmdDescArray;
};

//从程序参数中解析出各个命令
struct CmdLineDescription* parse_args(int argc, char* argv[]){
    if (argc <= 1) {
        //perror("error: no arguments inputed\n");
        printf("error: no arguments inputed\n");
        return NULL;
    }

    if (strcmp(argv[1], "|") == 0) {
        printf("error: the first argument is |\n");
        return NULL;
    }

    if (strcmp(argv[argc - 1], "|") == 0) {
        printf("error: the last argument is |\n");
        return NULL;
    }

    int cmd_num = 1;
    int i;
    for(i = 2; i < argc; i++ ) {
        if (strcmp(argv[i], "|") == 0) {
            if (strcmp(argv[i -1], "|") == 0) {
                 printf("error: successive \'|\' in arguments\n");
                 exit(1);
            }
            cmd_num++;
        }
    }

//    int size = sizeof(struct CmdLineDescription) + sizeof(struct CmdDescription) * cmd_num;
//    //printf("size = %d\n",size);
//    struct CmdLineDescription * cmdLineDesc = (struct CmdLineDescription *)malloc(size);
//    if (cmdLineDesc == NULL) {
//        perror("program failed to alloc memory when parse arguments\n");
//        exit(-1);
//    }
//    memset(cmdLineDesc, 0, sizeof(size));
//    cmdLineDesc->cmd_num = cmd_num;

    int size = sizeof(struct CmdLineDescription) + sizeof(struct CmdDescription) * cmd_num;
    struct CmdLineDescription * cmdLineDesc = (struct CmdLineDescription *)malloc(sizeof(struct CmdLineDescription));
    cmdLineDesc->cmd_num = cmd_num;
    cmdLineDesc->cmdDescArray = (struct CmdDescription*)malloc(sizeof(struct CmdDescription) * cmd_num);
    
    int cmd_idx = 0;
    int j;
    for(j = 1; j < argc; j++ ) {
       //struct CmdDescription *currentCmdDesc = &(cmdLineDesc->cmdDescArray[cmd_idx]);
       if (strcmp(argv[j], "|") != 0) {
           //if (currentCmdDesc->cmdNameIndexInArgv == 0) {
           if (cmdLineDesc->cmdDescArray[cmd_idx].cmdNameIndexInArgv == 0) {
                 cmdLineDesc->cmdDescArray[cmd_idx].cmdNameIndexInArgv = j;
                cmdLineDesc->cmdDescArray[cmd_idx].lastCmdArgIndexInArgv = j;
                //printf("parsed cmd[%d]:%s", cmd_idx, argv[j]);
           } else {
                cmdLineDesc->cmdDescArray[cmd_idx].lastCmdArgIndexInArgv = j;
                //printf(" %s",  argv[j]);
           }

           //printf("~~~~~ %d -> %d\n", cmdLineDesc->cmdDescArray[cmd_idx].cmdNameIndexInArgv, cmdLineDesc->cmdDescArray[cmd_idx].lastCmdArgIndexInArgv);
       } else {
          // '|' 之后是新的cmd
          cmd_idx++;
          //printf("\n");
       }
    }

    return cmdLineDesc;
}


int main(int argc, char* argv[])
{
    struct CmdLineDescription * cmdLineDesc = parse_args(argc, argv);
    if (NULL == cmdLineDesc) {
        exit(1);
    }
    //printf("\n... to rum %d cmds by pipe:\n\n", cmdLineDesc->cmd_num);

    pid_t pid,wpid;
    int cmd_idx, i, status;

    int pipe_num = cmdLineDesc->cmd_num - 1;
    //每个管道需要2个fd
    int (*fdPairArr)[2] =(int (*)[2]) malloc(pipe_num * 2 * sizeof(int));
    for( cmd_idx = 0; cmd_idx < cmdLineDesc->cmd_num; cmd_idx++ ) {
        //预先创建好需要的管道
        int *fdPair = fdPairArr[cmd_idx];
        pipe(fdPair);
    }

    //数组的每个item，是各命令用于执行execvp()的char *argv[]
    //必须在父进程分配内存，最后由父进程释放。因为子进程执行execvp()之后运行的是cmd的代码，无法执行释放我们释放内存的代码
    char **cmdArgvArray[cmdLineDesc->cmd_num];
    for(cmd_idx = 0; cmd_idx < cmdLineDesc->cmd_num; cmd_idx++ ) {
        struct CmdDescription currentCmd = cmdLineDesc->cmdDescArray[cmd_idx];
        //构造每个命令的参数列表
        int cmdArgNum = currentCmd.lastCmdArgIndexInArgv - currentCmd.cmdNameIndexInArgv;
        
        char **cmdArgv = (char **)malloc(sizeof(char*) * (cmdArgNum + 2));
        if (cmdArgv == NULL) {
            printf("child process failed to alloc memory\n");
            exit(1);
        }
        
        int j, k;
        // printf("cmd[%d], argNum %d:", cmd_idx, cmdArgNum);
        for(j = currentCmd.cmdNameIndexInArgv, k = 0; j <= currentCmd.lastCmdArgIndexInArgv; j++, k++) {
          cmdArgv[k] = argv[j];
          //printf(" %s", cmdArgv[k]);
        }
        cmdArgv[cmdArgNum + 1] = NULL; //execvp()要求这个数组参数最后一个成员必须是NULL
        cmdArgvArray[cmd_idx] = cmdArgv; //为每个命令malloc的char *argv[]即到数据项里
        
//        printf("#### cmd[%d] argv: ", cmd_idx);
//        for(j = 0; cmdArgvArray[cmd_idx][j] != NULL; j++) {
//            printf("%s ", cmdArgvArray[cmd_idx][j]);
//         }
//        printf("\n");
    }
    
    //创建各个子进程，用来执行每个命令
    for(cmd_idx = 0; cmd_idx < cmdLineDesc->cmd_num; cmd_idx++ ) {
        if((pid = fork()) == 0)
        {
            //子进程
            break;
        }else if( pid < 0 )
        {
            printf("fork error");
            exit(1);
        }
    }

    if (cmd_idx < cmdLineDesc->cmd_num) {
         //为执行各命令做准备
        struct CmdDescription currentCmd = cmdLineDesc->cmdDescArray[cmd_idx];
        char * cmd = argv[currentCmd.cmdNameIndexInArgv]; //命令的名字

         //子进程处理各个fd，用不着的要关掉
        if (cmd_idx == 0) {
          //第一个命令，关闭第一个管道的输入，stdout设置成管道的输出
          close(fdPairArr[0][0]);
          if (cmdLineDesc->cmd_num > 1) {
            dup2(fdPairArr[0][1], STDOUT_FILENO);
            int l;
            for (l = 1; l < pipe_num; l++) {
              close(fdPairArr[l][0]);
              close(fdPairArr[l][1]);
            }
          }
        } else if (cmd_idx == cmdLineDesc->cmd_num - 1) {
          //最后一个命令, stdin设置为管道的输入, 关闭管道的输出
          dup2(fdPairArr[pipe_num - 1][0], STDIN_FILENO);
          close(fdPairArr[pipe_num - 1][1]);

         int l;
          for (l = 0; l < pipe_num - 1; l++) {
              close(fdPairArr[l][0]);
              close(fdPairArr[l][1]);
          }
        } else if (0 < cmd_idx )  {
          //中间部分的命令
          int l;
          for (l = 0; l < pipe_num; l++) {
            if (l == cmd_idx -1 || l == cmd_idx ) {
              continue;
            }

            close(fdPairArr[l][0]);
            close(fdPairArr[l][1]);
          }

          dup2(fdPairArr[cmd_idx - 1][0], STDIN_FILENO);
          close(fdPairArr[cmd_idx - 1][1]);

          close(fdPairArr[cmd_idx][0]);
          dup2(fdPairArr[cmd_idx][1], STDOUT_FILENO);
        }

       execvp(cmd, cmdArgvArray[cmd_idx]); //运行命令
       printf("execute cmd[%d] error, cmd name: %s\n", cmd_idx, cmd);
       exit(1);
    } else {
        //运行到这里，则是父进程
        //为了不影响子进程的管道通信, 关闭所有管道的fd, 而且必须放在fork完子进程后才可以关闭。
        for (i = 0; i < cmdLineDesc->cmd_num; i++) {
            close(fdPairArr[i][0]);
            close(fdPairArr[i][1]);
        }

        // 父进程 回收子进程
        while( (wpid = waitpid(-1, &status, WNOHANG)) != -1 )
        {
            if(wpid > 0)
            {
                //printf("child pid = %d,by recycle.", wpid);
                if(WIFEXITED(status))
                {
                    //程序正常退出
                    //printf("normal exit, exit num = %d\n", WEXITSTATUS(status));
                } else if( WIFSIGNALED(status) ) {
                    //程序被信号终止
                    //printf("terminate by signal, signal num = %d\n", WTERMSIG(status));
                }
            }
        }

        free(fdPairArr);
        fdPairArr = NULL;
        
        for(cmd_idx = 0; cmd_idx < cmdLineDesc->cmd_num; cmd_idx++ ) {
            free(cmdArgvArray[cmd_idx]);
            cmdArgvArray[cmd_idx] = NULL;
        }
        free(cmdLineDesc->cmdDescArray);
        cmdLineDesc->cmdDescArray = NULL;
        free(cmdLineDesc);
        cmdLineDesc = NULL;
    }

    return 0;
}
