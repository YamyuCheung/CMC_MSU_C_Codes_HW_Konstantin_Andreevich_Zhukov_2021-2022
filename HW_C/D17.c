//
//  D17.c
//  c
//
//  Created by Xinyu Zhang on 29/11/2021.
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

int main(int argc, const char *argv[])
{
    int fd[2], semid, cnt = 0;
    int Cnt_Max, ff;
    struct sembuf P1 = {0, -1, 0}, V1 = {0, 1, 0}; //семафор 0
    struct sembuf P2 = {1, -1, 0}, V2 = {1, 1, 0}; //семафор 1
    key_t key;
    pid_t pid;
    
    ff = creat("a.txt", 0664);
    if (ff < 0) {
        perror("open");
        return 1;
    }
    key = ftok("a.txt", 'w'); //создали ключ
    close(ff);
    if (key < 0){
        perror("ftok");
        return 2;
    }

    semid = semget(key, 2, IPC_CREAT | 0666); //создали массив из 2 семафоров
    if (semid < 0){
        perror("semid");
        return 3;
    }
    semctl(semid, 0, SETVAL, 0); //sem_val1 = 0
    semctl(semid, 1, SETVAL, 0); //sem_val2 = 0

    scanf("%d", &Cnt_Max); //прочитали максимум
    if(pipe(fd) < 0 ){
        
        
        
        perror("pipe");
        return 4;
    }//создали канал

    pid = fork();
    if (pid < 0 ) {
        perror("fork");
        return 5;
    }
    if (pid > 0) //код отца
    {
        write(fd[1], &cnt, sizeof(int)); //записали cnt в канал
        semop(semid, &V1, 1);
        while(cnt <Cnt_Max)
        {
            semop(semid, &P2, 1);
            read(fd[0],&cnt, sizeof(int));
            printf("father %d\n", cnt++);
            fflush(stdout);
            write(fd[1], &cnt, sizeof(int));
            semop(semid, &V1, 1);
        }
        close(fd[0]);
        close(fd[1]);
        wait(NULL);

    }
    else
    {
        while(cnt < Cnt_Max)
        {
            semop(semid, &P1, 1);
            read(fd[0], &cnt, sizeof(int));
            printf("son %d\n", cnt++);
            fflush(stdout);
            write(fd[1], &cnt, sizeof(int));
            semop(semid, &V2, 1);
        }
        close(fd[0]);
        close(fd[1]);
        return 0;
    }
    semctl(semid, 0, IPC_RMID, 0);
    return 0;


}

