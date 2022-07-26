//
//  B10.c
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
void transfer(unsigned short sum)
{
    unsigned short temp = 0, year = 0, month = 0, day = 0;
    temp = sum;
    year = temp>>9;
    month = (temp>>5) & 15;
    day = temp & 31;
//    printf("%d\n", year);
    if (year <= 49)
    {
        year = 2000+year;
        printf("%hd %hd %hd\n", year, month, day);
    }
    else if (year >= 50)
    {
        year = 1900+year;
        printf("%hd %hd %hd\n", year, month, day);
    }
}

int main(int argc, const char * argv[]) {
    unsigned short sum = 0;
    scanf("%hd", &sum);
    transfer(sum);
    return 0;
}
