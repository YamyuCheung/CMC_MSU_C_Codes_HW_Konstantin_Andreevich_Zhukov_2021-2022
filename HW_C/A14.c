//
//  A14.c
//  c
//
//  Created by Xinyu Zhang on 10.09.2021.
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
#define SIZE 10

int main(int argc, const char * argv[]) {
    int counter, evens[SIZE], num, digit;
    scanf("%d", &num);
    for (counter = 0; counter < SIZE; counter++)
    {
        evens[counter] = 0;
    }
    
    while (num)
    {
        digit = num%10;
        evens[digit]++;
        num/=10;
    }
    
    
    for (counter=0; counter < SIZE; counter++)
    {
        if (evens[counter] >= 2)
        {
            printf("%d ", counter);
            
        }
    }
    
    printf("\n");
    
    return 0;
}
