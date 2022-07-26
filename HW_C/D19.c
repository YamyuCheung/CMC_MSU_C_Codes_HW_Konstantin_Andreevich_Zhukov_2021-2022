//
//  D19.c
//  c
//
//  Created by Xinyu Zhang on 04/12/2021.
//
//
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
//               佛祖保佑         永無BUG
//
//
//
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>

volatile sig_atomic_t flag = 0;
int main(int argc, const char * argv[])
{
    int fd[2], semid, counter = 0;
    int counter_max, ff;
    struct sembuf P1 = {0, -1, 0}, V1 = {0, 1, 0};
    struct sembuf P2 = {1, -1, 0}, V2 = {1, 1, 0};
    struct sembuf P3 = {2, -1, 0}, V3 = {2, 1, 0};
    key_t key;
    pid_t pid, pid_son2;

    ff = creat("a.txt", 0644);
    if (ff < 0)
    {
        perror("open");
        return 1;
    }
    key = ftok("a.txt", 'w');
    if (key < 0){
        perror("ftok");
        return 1;
    }
    semid = semget(key, 3, IPC_CREAT | 0666);
    if (semid < 0)
    {
        perror("semid");
        return 1;
    }
    semctl(semid, 0, SETVAL, 0);
    semctl(semid, 1, SETVAL, 0);
    semctl(semid, 2, SETVAL, 0);
    scanf("%d", &counter_max);
    if (pipe(fd) < 0){
        perror("pipe");
        return 1;
    }

    if ((pid = fork()) < 0){
        perror("fork");
        return 1;
    }
    else if (pid > 0){
        if ((pid_son2 = fork()) < 0){
            perror("fork");
            return 1;
        }
        else if (pid_son2 == 0){
            while(counter < counter_max){
                semop(semid, &P3, 1);
                read(fd[0], &counter, sizeof(int));
                if (counter <= counter_max){
                    printf("son2 %d\n", counter++);
                    fflush(stdout);
                    write(fd[1], &counter, sizeof(int));
                    semop(semid, &V1, 1);
                }
            }
            close(fd[0]); close(fd[1]);
            return 0;
        }
        else{
            semop(semid, &V3, 1);
            write(fd[1], &counter, sizeof(int));
            while (counter < counter_max){
                semop(semid, &P2, 1);
                read(fd[0], &counter, sizeof(int));
                if (counter <= counter_max){
                    printf("father %d\n", counter++);
                    fflush(stdout);
                    write(fd[1], &counter, sizeof(int));
                    semop(semid, &V3, 1);
                }
            }
            close(fd[0]); close(fd[1]);
            wait(NULL);
        }
    }
    else{
        while(counter <= counter_max){
            semop(semid, &P1, 1);
            read(fd[0], &counter, sizeof(int));
            if (counter <= counter_max){
                printf("son1 %d\n", counter++);
                fflush(stdout);
                write(fd[1], &counter, sizeof(int));
                semop(semid, &V2, 1);
            }
        }
        close(fd[0]); close(fd[1]);
        return 0;
    }
    semctl(semid, 0, IPC_RMID, 0);
    return 0;
}
