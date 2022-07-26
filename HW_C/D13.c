//
//  D13.c
//  c
//
//  Created by Xinyu Zhang on 22/11/2021.
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
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main(int argc, char * argv[])
{
    pid_t pid;
    if (argc < 5){
        printf("Use: %s pr1 arg1 arg2 file\n", argv[0]);
        return 1;
    }
    pid = fork();
    if (pid == -1) { perror("fork"); return 2;}
    else if (pid == 0) //код сына
    {
        int fd;
        fd = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        // fd = creat(argv[argc-1], 0644);
        if (fd == -1){
            perror("open");
            return 3;
        }
        dup2(fd, 1);
        close(fd);
        execlp(argv[1], argv[1], argv[2], argv[3], NULL); //pr1 arg1 arg2 // ls -l -a
        perror("exec");
        return 2;
    }
    wait(NULL);

    return 0;
}
