//
//  D16.c
//  c
//
//  Created by Xinyu Zhang on 29/11/2021.
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

volatile sig_atomic_t flag = 0, flag2 = 0, counter = 0;
void Handler(int s)
{
    signal(SIGUSR1, Handler);
    flag = 1;
}


int main(int argc, const char *argv[])
{
    pid_t pid = 0, pid_f, pid_son2;
    int fd[2], cnt = 1, Cnt_Max;
    scanf("%d", &Cnt_Max);
    if (pipe(fd) < 0){
        perror("pipe");
        return 1;
    }

    signal(SIGUSR1, Handler);
    
    if ((pid = fork()) < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid > 0)
    {
        if ((pid_son2 = fork()) < 0)
        {
            perror("fork");
            return 1;
        }
        else if (pid_son2 == 0)
        {
//            printf("PID son2 = %d father PID son2 = %d\n", getpid(), getppid());
            pid_f = getppid();
            while (cnt < Cnt_Max)
            {
                if (!flag) pause();
                flag = 0;
                read(fd[0], &cnt, sizeof(int)); //read from pipe cnt
                printf("son2 %d\n", cnt++);
                fflush(stdout);
                write(fd[1], &cnt, sizeof(int)); //write to pipe cnt
                kill(pid_f, SIGUSR1);
            }
            close(fd[0]); close(fd[1]);
        }
        else
        {
//            printf("my PID = %d pid = %d pid_son2 = %d\n", getpid(), pid, pid_son2);
            write(fd[1], &cnt, sizeof(int)); //отец начинает игру и первый пишет число в канал
            kill(pid, SIGUSR1);
            while(cnt < Cnt_Max)
            {
                if (!flag) pause(); //ждет сигнал от сына
                flag = 0;
                read(fd[0], &cnt, sizeof(int));
                printf("father %d\n", cnt++);
                fflush(stdout);
                write(fd[1], &cnt, sizeof(int));
//                printf("cnt = %d\n", cnt);
                if (flag2 == 0)
                {
                    if (cnt <= Cnt_Max)
                    {
                        kill(pid_son2, SIGUSR1);
                    }
                    flag2 = 1;
                }
                else
                {
                    if (cnt <= Cnt_Max)
                    {
                        kill(pid, SIGUSR1);
                    }
                    flag2 = 0;
                }
            }
            close(fd[0]);
            close(fd[1]);
        }
    }
    else if (pid == 0)
    {
//        printf("PID son1 = %d father PID son1 = %d\n", getpid(), getppid());
        pid_f = getppid();
        while (cnt <= Cnt_Max)
        {
            if (!flag) pause();
            flag = 0;
            read(fd[0], &cnt, sizeof(int)); //read from pipe cnt
            printf("son1 %d\n", cnt++);
            fflush(stdout);
            write(fd[1], &cnt, sizeof(int)); //write to pipe cnt
            kill(pid_f, SIGUSR1);
        }
        close(fd[0]); close(fd[1]);
    }
    


    return 0;
}
