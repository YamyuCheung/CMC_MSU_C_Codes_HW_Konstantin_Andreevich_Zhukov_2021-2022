//
//  B9.c
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
void transfer(short year, short month, short day)
{
    unsigned short mask = 1, sum = 0;
    mask <<= sizeof(mask)*8-1;
    year <<= 9;
    month <<= 5;
    sum = year + month + day;
    while (mask) {
        if (mask & sum)
            printf("1");
        else
            printf("0");
        mask >>= 1;
    }
    printf("\n");
    printf("%u\n", sum);
}

int main(int argc, const char * argv[]) {
    unsigned short year = 0, month = 0, day = 0;
    scanf("%hd %hd %hd", &year, &month, &day);
    transfer(year, month, day);
    
    return 0;
}
