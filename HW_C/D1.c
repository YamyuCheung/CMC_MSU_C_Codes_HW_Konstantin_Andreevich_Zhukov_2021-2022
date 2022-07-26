//
//  D1.c
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
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, const char * argv[])
{
    int fd1, fd2;
    ssize_t n;
    char buf[256];
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
        fprintf(stderr, "couldn't open file %s\n", argv[2]);
        close(fd1);
        return 3;
    }
    while ((n = read(fd1, buf, 256)) > 0)
    {
        write(fd2, buf, n);
    }
    
    close(fd1);
    close(fd2);

    return 0;
}
