//
//  D10.c
//  c
//
//  Created by Xinyu Zhang on 19/11/2021.
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
//               佛祖保佑         永无BUG
//
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
//pr1 argv1 argv2 | pr2
int main(int argc, const char * argv[])
{
    int fd[2];
    pid_t pid1, pid2;
    if (argc < 4)
    {
        printf("Use: ./a.out pr1 arg1 arg2 arg3 pr2\n");
        return 1;
    }
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 2;
    }
    pid1 = fork(); //код отца
//    printf("%d %d\n", getpid(), getppid());
    if (pid1 == -1)
    {
        perror("fork1");
        return 3;
    }
    else if (pid1 == 0) //код сына 1
    {
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        execlp(argv[1], argv[1], argv[2], argv[3], NULL);
        perror("execlp1");
        return 4;
    }
    pid2 = fork(); //код отца
//    printf("%d %d\n", getpid(), getppid());
    if (pid2 == -1)
    {
        perror("fork2");
        return 5;
    }
    else if (pid2 == 0) //код сына 2
    {
        dup2(fd[0], 0);
        close(fd[0]);
        close(fd[1]);
        execlp(argv[4], argv[4], NULL);
        perror("execlp2");
        return 6;
    }
    // код отца
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}
