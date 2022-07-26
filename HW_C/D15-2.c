//
//  D15-2.c
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
int counter1 = 0, counter2 = 0, flag = 0;

void fun(int signum)
{
    if (signum == SIGINT)
    {
        signal(SIGINT, fun);
        counter1++;
        flag = 1;
        if (counter1 == 7)
        {
            signal(SIGINT, SIG_DFL);
        }
    }
    if (signum == SIGQUIT)
    {
        signal(SIGQUIT, fun);
        counter2++;
        if (counter2 % 2 == 0)
        {
            printf("SIGINT %d times, SIGQUIT %d times\n", counter1, counter2);
        }
    }
}

int main(int argc, const char *argv[])
{
    signal(SIGINT, fun);
    signal(SIGQUIT, fun);
//    kill(getpid(), SIGINT);
//    raise(SIGINT);
//    kill(getpid(), SIGQUIT);
//    raise(SIGQUIT);
    while(1)
    {
        if (flag)
        {
//            printf("SIGINT %d times\n", counter1);
            flag = 0;
        }
    }
}
