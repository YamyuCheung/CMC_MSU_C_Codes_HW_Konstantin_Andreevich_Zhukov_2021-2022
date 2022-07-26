//
//  B7.c
//  c
//
//  Created by Xinyu Zhang on 20.09.2021.
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

void print_bin(short num)
{
    unsigned short mask = 1;
    mask <<= sizeof(short)*8 - 1;
    while(mask)
    {
        if (mask & num)
            printf("1");
        else
            printf("0");
        mask >>= 1;
    }
    printf("\n");
    
}

int main(int argc, const char * argv[]) {
    short sh;
    scanf("%hd", &sh);
    print_bin(sh);
    
    return 0;
}
