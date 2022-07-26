//
//  D5.c
//  c
//
//  Created by Xinyu Zhang on 12/11/2021.
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
#include <unistd.h>
#include <fcntl.h>
int main(int argc, const char * argv[])
{
    int fd1, fd2, buf1, buf2, counter = 0, i, j, buf3;
    long buf1_p, buf2_p, cur_p;
    if (argc < 3)
    {
        printf("Use ./exe input.bin output.bin\n");
        return 1;
    }
    fd1 = open("input.bin", O_RDWR);
    if (fd1 == -1)
    {
        perror("open");
        creat(argv[2], 0644);
        return 1;
    }
    fd2 = creat(argv[2], 0644);
    if (fd2 == -1)
    {
        perror("creat");
        close(fd1);
        return 1;
    }
    if (read(fd1, &buf1, sizeof(int)) != sizeof(int))
    {
        creat(argv[2], 0644);
        return 1;
    }
    lseek(fd1, 0L, SEEK_SET);
    while(read(fd1, &buf1, sizeof(int)) == sizeof(int))
    {
        counter++;
    }
    lseek(fd1, 0L, SEEK_SET);
    
    for (i = 0; i < counter-1; i++)
    {
        for (j = 0; j < counter-i-1; j++)
        {
            read(fd1, &buf1, sizeof(int));
            buf1_p = lseek(fd1, 0, SEEK_CUR)-sizeof(int);
            read(fd1, &buf2, sizeof(int));
            buf2_p = lseek(fd1, 0, SEEK_CUR)-sizeof(int);
//            printf("%d %d ", buf1, buf2);
//            printf("\n");
            cur_p = lseek(fd1, 0, SEEK_CUR)-sizeof(int);
            if (buf1 < buf2)
            {
                lseek(fd1, buf1_p, SEEK_SET);
                write(fd1, &buf2, sizeof(int));
                lseek(fd1, buf2_p, SEEK_SET);
                write(fd1, &buf1, sizeof(int));
            }
            lseek(fd1, cur_p, SEEK_SET);
        }
        lseek(fd1, 0L, SEEK_SET);
    }
    lseek(fd1, 0L, SEEK_SET);
    
    while (read(fd1, &buf3, sizeof(int)) == sizeof(int))
    {
        write(fd2, &buf3, sizeof(int));
    }
    close(fd1);
    close(fd2);
    
    return 0;
}
