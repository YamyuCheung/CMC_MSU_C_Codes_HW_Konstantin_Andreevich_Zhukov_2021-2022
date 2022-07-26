//
//  A13.c
//  c
//
//  Created by Xinyu Zhang on 10.09.2021.
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

int main(int argc, const char * argv[]) {
    int num, maxd, mind, digit;
    scanf("%d", &num);
    maxd = num%10;
    mind = maxd;
    while (num)
    {
        digit = num%10;
        if (digit > maxd)
            maxd = digit;
        if (digit < mind)
            mind = digit;
        num /= 10;
    }
    printf("%d %d\n", mind, maxd);

    return 0;
}
