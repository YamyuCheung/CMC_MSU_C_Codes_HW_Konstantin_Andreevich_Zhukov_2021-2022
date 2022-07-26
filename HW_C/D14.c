//
//  D14.c
//  c
//
//  Created by Xinyu Zhang on 22/11/2021.//
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
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    if (argc < 4)
    {
        printf("Use: %s pr1 arg1 file\n", argv[0]);
        return 1;
    }
    pid = fork();
    if (pid == -1) {perror("fork"); return 1;}
    else if (pid == 0)
    {
        int fd;
        fd = open(argv[argc-1], O_RDONLY);
        if (fd == -1){
            perror("open");
            return 1;
        }
        dup2(fd, 0);
        close(fd);
        execlp(argv[1], argv[1], argv[2], NULL);
        perror("exec");
        return 1;
    }
    wait(NULL);
    return 0;
}
