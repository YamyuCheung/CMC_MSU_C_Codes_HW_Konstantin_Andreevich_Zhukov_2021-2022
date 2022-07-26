//
//  D9.c
//  c
//
//  Created by Xinyu Zhang on 16/11/2021.
//
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
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

void createsubprocess(int num)
{
    int fd[2], m, flag = 0, min = 0, max = 0;
    pid_t pid  = 0;
    int  i;
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return;
    }

    for (i=0; i<num; i++)
    {
        pid=fork();
        if (pid == 0||pid == -1)
        {
            break ;
        }
    }
    if (pid == -1)
    {
        perror("fail to fork!\n" );
        return;
    }
    else if (pid==0)
    {
        if (i == 0)
        {
            int n;
            close(fd[0]);
            while(scanf("%d", &n) == 1)
            {
                write(fd[1], &n, sizeof(int));
            }
            close(fd[1]);
        }
        if (i == 1)
        {
            close(fd[1]);
            while(read(fd[0], &m, sizeof(int)) > 0)
            {
                if (flag == 0)
                {
                    min = max = m;
                    flag = 1;
                }
                if (flag == 1)
                {
                    if (min > m)
                    {
                        min = m;
                    }
                    if (max < m)
                    {
                        max = m;
                    }
                }
            }
            close(fd[0]);
            printf("%d %d\n", min, max);
        }
    }
    else
    {
        close(fd[1]);
        close(fd[0]);
        wait(NULL);
    }

}

int main(int argc, const char * argv[])
{
    createsubprocess(2);
    return 0;
}
