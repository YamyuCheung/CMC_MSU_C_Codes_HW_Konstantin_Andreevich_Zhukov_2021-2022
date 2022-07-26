//
//  D15.c
//  c
//
//  Created by Xinyu Zhang on 26/11/2021.
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
#include <signal.h>

volatile sig_atomic_t flag = 0;
void Handler(int s)
{
    signal(SIGUSR1, Handler);
    flag = 1;
}

int main(int argc, const char * argv[])
{
    pid_t pid;
    int fd[2], cnt = 0, Cnt_Max; //код остановить пинг-понг
    scanf("%d", &Cnt_Max);
    if (pipe(fd) < 0) {perror("pipe"); return 1;}
    signal(SIGUSR1, Handler);
    
    pid = fork();
    if (pid < 0) {perror("fork"); return 2;}
    if (pid == 0) //код сына
    {
        pid_t pid_f = getppid(); //получить pid отца
        while(cnt < Cnt_Max)
        {
//            printf("flag = %d", flag);
            if (!flag) pause(); //wait
            flag = 0;
            read(fd[0], &cnt, sizeof(int)); //read from pipe cnt
            printf("son %d\n", cnt++);
            fflush(stdout);
            write(fd[1], &cnt, sizeof(int)); //write to pipe cnt
            kill(pid_f, SIGUSR1);
        }
        close(fd[0]); close(fd[1]);
    }
    else //код отца fork() -> pid = PID son
    {
        write(fd[1], &cnt, sizeof(int)); //отец начинает игру и первый пишет число в канал
        kill(pid, SIGUSR1);
        while(cnt < Cnt_Max)
        {
//            printf("flag father = %d", flag);
            if (!flag) pause(); //ждет сигнал от сына
            flag = 0;
            read(fd[0], &cnt, sizeof(int));
            printf("father %d\n", cnt++);
            fflush(stdout);
            write(fd[1], &cnt, sizeof(int));
            kill(pid, SIGUSR1);
//            printf("flag father = %d", flag);
        }
        close(fd[0]);
        close(fd[1]);
    }
    return 0;
}
