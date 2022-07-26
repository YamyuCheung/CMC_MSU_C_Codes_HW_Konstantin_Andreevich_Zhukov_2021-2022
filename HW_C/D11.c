//
//  D11.c
//  c
//
//  Created by Xinyu Zhang on 20/11/2021.
//
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

int main(int argc, const char * argv[])
{
    int fd[2], fd2[2];
    pid_t pid1, pid2, pid3;
    if (argc < 6)
    {
        printf("Use: ./a.out pr1 arg1 pr2 arg2 arg3 pr3\n");
        return 1;
    }
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 2;
    }
    if (pipe(fd2) == -1)
    {
        perror("pipe");
        return 3;
    }
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork1");
        return 4;
    }
    else if (pid1 == 0)
    {
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp(argv[1], argv[1], argv[2], NULL);
        perror("execlp1");
        return 5;
    }
    else
    {
        pid2 = fork();
        if (pid2 == -1)
        {
            perror("fork2");
            return 6;
        }
        else if (pid2 == 0)
        {
            dup2(fd[0], 0);
            dup2(fd2[1], 1);
            close(fd[0]);
            close(fd[1]);
            close(fd2[0]);
            close(fd2[1]);
            execlp(argv[3], argv[3], argv[4], argv[5], NULL);
            perror("execlp2");
            return 7;
        }
        else
        {
            pid3 = fork();
            if (pid3 == -1)
            {
                perror("fork3");
                return 8;
            }
            else if (pid3 == 0)
            {
                dup2(fd2[0], 0);
                close(fd[0]);
                close(fd[1]);
                close(fd2[0]);
                close(fd2[1]);
                execlp(argv[6], argv[6], NULL);
                perror("execlp3");
                return 9;
            }
        }
    }
    close(fd[0]);
    close(fd[1]);
    close(fd2[0]);
    close(fd2[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return 0;
}
