//
//  T1-1-real.c
//  c
//
//  Created by Xinyu Zhang on 22/12/2021.
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
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<string.h>
#include <signal.h>
int main(int argc, const char * argv[])
{
    unsigned short n, t, n2;
    char ch;
    scanf("%hd %c %hd", &n, &ch, &t);

    if (ch == 'u')
    {
        t <<= 6;
        n2 = t;
        n2 >>= 6;
        n2 <<= 6;
        n = n | n2;
        n = n^t;
    }
    else if (ch == 'g')
    {
        t <<= 3;
        n2 = t;
        n2 >>= 3;
        n2 <<= 3;
        n = n | n2;
        n = n^t;
    }
    else if (ch == 'o')
    {
        n2 = t;
        n = n | n2;
        n = n^t;
    }

    printf("%hu\n", n);


    return 0;
}
