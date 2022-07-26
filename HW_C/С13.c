//
//  С13.c
//  c
//
//  Created by Xinyu Zhang on 15.10.2021.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int i, flag, num;
    float sum_mul;
    if (argc < 4)
    {
        printf("Input Error\n");
        return 1;
    }
    if (!strcmp("sum", argv[1]))
    {
        flag = 1;
        sum_mul = 0.;
    }
    else if(!strcmp("mul", argv[1]))
    {
        flag = 0;
        sum_mul = 1.;
    }
    else
    {
        printf("Input Error\n");
        return 1;
    }
    num = atoi(argv[2]);
    num = num > argc-3 ? argc-3 : num;
    for(i = 0; i < num; i++)
    {
        float var = atof(argv[i+3]);
        if (flag)
        {
            sum_mul += var;
        }
        else
        {
            sum_mul *= var;
        }
    }

    printf("%g\n", sum_mul);


    return 0;
}
