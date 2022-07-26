//
//  B8.c
//  c
//
//  Created by Xinyu Zhang on 20.09.2021.
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


#include <stdio.h>
void transfer(short priority)
{
    unsigned short mask = 1, flag = 0;
    mask <<= sizeof(mask)*8-8;
    while (mask)
    {
        if (mask & priority)
        {
            if (flag == 0)
            {
                printf("r");
                flag++;
            }
            else if (flag == 1)
            {
                printf("w");
                flag++;
            }
            else if (flag == 2)
            {
                printf("x");
                flag=0;
            }
        }
        else
        {
            printf("-");
            flag++;
            if (flag == 3)
                flag = 0;
        }
        mask >>= 1;
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    unsigned short priority = 0;
    scanf("%ho", &priority);
    transfer(priority);
    return 0;
}
