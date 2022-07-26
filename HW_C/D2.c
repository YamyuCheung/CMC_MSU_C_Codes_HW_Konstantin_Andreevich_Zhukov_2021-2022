//
//  D2.c
//  c
//
//  Created by Xinyu Zhang on 08/11/2021.
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
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int fd1, fd2, *savec3, counter, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, flag = 0;
    ssize_t n;
    char buf[99], ch, digit;
    struct stat s;
    if (argc < 3)
    {
        printf("Use: ./exe first_file second_file\n");
        return 1;
    }
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        fprintf(stderr, "Couldn't open file %s\n", argv[1]);
        return 2;
    }
    stat(argv[1], &s);
    fd2 = creat(argv[2], s.st_mode);
    if (fd2 == -1)
    {
        fprintf(stderr, "Couldn't open file %s\n", argv[1]);
        close(fd1);
        return 3;
    }
    
    memset(buf, 0, sizeof(buf));
    
    while((n = read(fd1, buf, 99)) > 0)
    {
        for (counter = 0; counter < 99; counter++)
        {
            if ((buf[counter] >= 'A' && buf[counter] <= 'Z') || (buf[counter] >= 'a' && buf[counter] <= 'z') )
            {
                counter2++;
            }
            else if (buf[counter] == ',' || buf[counter] == '.' || buf[counter] == ' ' || buf[counter] == '\n')
            {
                if (buf[counter-1] != ',' && buf[counter-1] != '.')
                {
                    counter3++;
                    counter2 = 0;
                }
            }
//            printf("%d ", buf[counter]);
        }
    }
//    if (counter2)
//    {
//        counter3++;
//    }
//    printf("%d\n", counter3);
//    printf("\n");
    
    savec3 = (int*)malloc(counter3*sizeof(int));
    if (savec3 == NULL)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        return 4;
    }
    for (int i = 0; i < counter3; i++)
    {
        savec3[i] = -1;
    }
    
    lseek(fd1, 0L, SEEK_SET);
    counter2 = 0;
    memset(buf, 0, sizeof(buf));
    while((n = read(fd1, buf, 99)) > 0)
    {
        for (counter = 0; counter < 99; counter++)
        {
            if ((buf[counter] >= 'A' && buf[counter] <= 'Z') || (buf[counter] >= 'a' && buf[counter] <= 'z') )
            {
                counter2++;
            }
            else if (buf[counter] == ',' || buf[counter] == '.' || buf[counter] == ' ' || buf[counter] == '\n')
            {
                if (buf[counter-1] != ',' && buf[counter-1] != '.')
                {
                    if (counter2 != 0)
                    {
                        savec3[counter4] = counter2;
                        counter4++;
                    }
                }
                counter2 = 0;
            }
        }
    }
    if (counter2)
    {
        savec3[counter4] = counter2;
    }
    
    
//    for (int i = 0; i < counter3; i++)
//    {
//        printf("%d ", savec3[i]);
//    }
//    printf("\n");
    
    lseek(fd1, 0L, SEEK_SET);
    memset(buf, 0, sizeof(buf));
    while((n = read(fd1, buf, 1)) > 0)
    {
        if ((buf[counter5] >= 'A' && buf[counter5] <= 'Z') || (buf[counter5] >= 'a' && buf[counter5] <= 'z') )
        {
            write(fd2, &buf[counter5], sizeof(char));
            flag = 0;
        }
        else if (buf[counter5] == ',' || buf[counter5] == '.' || buf[counter5] == ' ' || flag == 0)
        {
            if (flag == 0)
            {
                if (savec3[counter6] >= 10)
                {
                    digit = (savec3[counter6]/10)%10;
                    ch = digit + '0';
                    write(fd2, &ch, sizeof(char));
                    digit = savec3[counter6]%10;
                    ch = digit + '0';
                    write(fd2, &ch, sizeof(char));
                    counter6++;
                    flag = 1;
                }
                else
                {
                    ch = savec3[counter6] + '0';
                    write(fd2, &ch, sizeof(char));
                    counter6++;
                    flag = 1;
                }
            }
            write(fd2, &buf[counter5], sizeof(char));
        }
        else
        {
            write(fd2, &buf[counter5], sizeof(char));
        }
    }
    close(fd1);
    close(fd2);
    free(savec3);
    savec3 = NULL;
    return 0;
}
