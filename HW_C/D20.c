//
//  D20.c
//  c
//
//  Created by Xinyu Zhang on 08/12/2021.
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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>
#include<sys/ipc.h>

struct msgbuf
{
    long mtype;
    char str[256];
    int cnt;
};
int main(int argc, const char *argv[])
{
    int D20key, msgid;
    pid_t pid_son1, pid_son2, pid_son3;
    key_t key;
    struct msgbuf message;
    if ((D20key=creat("D20key", 0644)) < 0)
    {
        return 1;
    }
    else
    {
        close(D20key);
    }
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid < 0)
    {
        perror("msgget");
        return 1;
    }
    if ((pid_son1=fork()) < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid_son1 == 0)
    {
        char str1[256];
        char sonsym1[2];
        sonsym1[0] = 'a';
        sonsym1[1] = '\0';
        msgrcv(msgid, &message, sizeof(message), 1, 0
        strcpy(str1, message.str);
        while(1)
        {
            message.mtype = 2;
            strcat(str1, sonsym1);
            strcpy(message.str, str1);
            if (sonsym1[0] != 'z')
            {
                sonsym1[0]++;
            }
            else
            {
                sonsym1[0]='a';
            }
            msgsnd(msgid, &message, sizeof(message), 0);
            if (strlen(str1) == message.cnt)
            {
                message.mtype = 5;
                msgsnd(msgid, &message, sizeof(message), 0);
                exit(1);
            }
            msgrcv(msgid, &message, sizeof(message), 4, 0);
            strcpy(str1, message.str);
            if (strlen(str1) == message.cnt)
            {
                message.mtype = 2;
                msgsnd(msgid, &message, sizeof(message), 0);
                exit(1);
            }
        }
        return 0;
    }
    else
    {
        if ((pid_son2 = fork()) < 0)
        {
            perror("fork");
            return 1;
        }
        else if (pid_son2 == 0)
        {
            char str2[256];
            char sonsym2[2];
            sonsym2[0] = '0';
            sonsym2[1] = '\0';
            while(1)
            {
                msgrcv(msgid, &message, sizeof(message), 2, 0);
                message.mtype = 3;
                strcpy(str2, message.str);
                if (strlen(str2) == message.cnt)
                {
                    msgsnd(msgid, &message, sizeof(message), 0);
                    exit(1);
                }
                strcat(str2, sonsym2);
                strcpy(message.str, str2);
                if (sonsym2[0] != '9')
                {
                    sonsym2[0]++;
                }
                else
                {
                    sonsym2[0] = '0';
                }
                msgsnd(msgid, &message, sizeof(message), 0);
                if (strlen(str2) == message.cnt)
                {
                    message.mtype = 5;
                    msgsnd(msgid, &message, sizeof(message), 0);
                    exit(0);
                }
            }
            return 0;
        }
        else
        {
            if ((pid_son3 = fork()) < 0)
            {
                perror("fork");
                return 1;
            }
            else if (pid_son3 == 0)
            {
                char str3[256];
                char sonsym3[2];
                sonsym3[0] = 'A';
                sonsym3[1] = '\0';
                while (1)
                {
                    msgrcv(msgid, &message, sizeof(message), 3, 0);
                    message.mtype = 4;
                    strcpy(str3, message.str);
                    if (strlen(str3) == message.cnt)
                    {
                        message.mtype = 4;
                        msgsnd(msgid, &message, sizeof(message), 0);
                        exit(1);
                    }
                    strcat(str3, sonsym3);
                    strcpy(message.str, str3);
                    if (sonsym3[0] != 'Z')
                    {
                        sonsym3[0]++;
                    }
                    else
                    {
                        sonsym3[0] = 'A';
                    }
                    msgsnd(msgid, &message, sizeof(message), 0);
                    if (strlen(str3) == message.cnt)
                    {
                        message.mtype = 5;
                        msgsnd(msgid, &message, sizeof(message), 0);
                        exit(0);
                    }
                }
                return 0;
            }
            else
            {
                scanf("%d", &message.cnt);
                message.mtype = 1;
                message.str[0] = '\0';
                msgsnd(msgid, &message, sizeof(message), 0);
                msgrcv(msgid, &message, sizeof(message), 5, 0);
                printf("%s\n", message.str);
                wait(NULL);
                wait(NULL);
                wait(NULL);
                msgctl(msgid, IPC_RMID, 0);
                return 0;
            }
        }
    }
    return 0;
}

