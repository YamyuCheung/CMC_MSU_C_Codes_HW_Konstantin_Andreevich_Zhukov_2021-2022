//
//  D4.c
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
    int fd;
    long temp, max, max_p;
    if (argc < 2)
    {
        printf("Use: ./exe file\n");
        return 1;
    }
    fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    if (read(fd, &temp, sizeof(long)) == sizeof(long))
    {
        max = temp;
        max_p = 0;
    }
    else
    {
        creat("input.bin", 0644);
        return 1;
    }
    while (read(fd, &temp, sizeof(long)) == sizeof(long))
    {
        if (temp > max)
        {
            max = temp;
            max_p = lseek(fd, 0, SEEK_CUR) - sizeof(long);
        }
    }
    max*=2;
    lseek(fd, max_p, SEEK_SET);
    write(fd, &max, sizeof(long));
    close(fd);
    return 0;
}
