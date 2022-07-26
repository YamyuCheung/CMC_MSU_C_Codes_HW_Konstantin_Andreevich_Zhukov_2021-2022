//
//  D7.c
//  c
//
//  Created by Xinyu Zhang on 15/11/2021.
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

int main(int argc, const char * argv[])
{
    int n = 0, i = 0, counter = 0;
    pid_t pid;
    scanf("%d", &n);
    pid = getpid();
    
    for (i = 0; i <= n; i++)
    {
        if (pid > 0)
        {
            counter++;
            pid = fork();
            wait(NULL);
        }
        else if (pid == 0)
        {
//            printf("pid %d PID %d PPID %d\n", pid, getpid(), getppid());
            printf("son %d\n", counter);
            break;
        }
        
    }

    return 0;
}
