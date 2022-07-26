//
//  D8.c
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

int main(int argc, const char * argv[])
{
    int n = 0, i = 0;
    pid_t pid, ppid;
    scanf("%d", &n);
    ppid = getpid();
    
    pid = fork();
    for (i = 1; i <= n; i++)
    {
        if (pid == -1)
        {
            perror("fork");
            return 1;
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else if (pid == 0)
        {
            printf("%d %d\n", getpid()-getppid(), getpid()-ppid);
            fflush(stdout);
            pid = fork();
        }
    }

    return 0;
}
