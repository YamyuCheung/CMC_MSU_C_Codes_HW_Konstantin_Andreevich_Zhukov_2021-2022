//
//  D3.c
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

int main(int argc, const char *argv[])
{
    int fd;
    int max, min, a;
    long max_p, min_p;
    fd = open("data.bin", O_RDWR); //открываем файл на чтение и на запись
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    if (read(fd, &a, sizeof(int)) == sizeof(int)) //прочитали первое число из файла
    {
        max = min = a;
        max_p = min_p = 0; //текущая позиция максимума и минимума начало файла
    }
    else
    {
        return 0;
    }

    while(read(fd, &a, sizeof(int)) == sizeof(int)) //пока может прочитать 4 байта
    {
        if (a > max)
        {
            max = a;
            max_p = lseek(fd, 0, SEEK_CUR) - sizeof(int);
        }
        if (a < min)
        {
            min = a;
            min_p = lseek(fd, 0, SEEK_CUR) - sizeof(int);
        }
    }

    lseek(fd, max_p, SEEK_SET); //переместить позицию на место максимума
    write(fd, &min, sizeof(int)); //записали минимум на место максимума
    lseek(fd, min_p, SEEK_SET); //переместить позицию на место минимума
    write(fd, &max, sizeof(int)); //записали максимум на место минимума
    close(fd);



    return 0;
}
