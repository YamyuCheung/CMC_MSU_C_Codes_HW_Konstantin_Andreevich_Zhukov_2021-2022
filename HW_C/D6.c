//
//  D6.c
//  c
//
//  Created by Xinyu Zhang on 15/11/2021.
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
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, const char * argv[])
{
    int fd[2];
    pid_t pid;
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }
    pid = fork(); //создаем процесс-сын
    if (pid == -1)
    {
        perror("fork");
        return 2;
    }
    else if (pid > 0) //код отца
    {
        int n;
        close(fd[0]);
        while(scanf("%d", &n) == 1)
        {
            write(fd[1], &n, sizeof(int)); //записываем числа в канал
        }
        close(fd[1]);
        wait(NULL); //ждет сына
    }
    else
    {//код сына
        int m, sum = 0;
        close(fd[1]);
        while(read(fd[0], &m, sizeof(int)) > 0) //читает пока есть в канале числа
        {
            sum += m;
        }
        close(fd[0]);
        printf("%d\n", sum);
    }



    return 0;
}
