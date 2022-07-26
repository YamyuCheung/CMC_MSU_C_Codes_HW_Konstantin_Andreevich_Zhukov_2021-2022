//
//  B2.c
//  c
//
//  Created by Xinyu Zhang on 18.09.2021.
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
#include <math.h>

int transfer(int a, int b)
{
    int i = 0, temp, m, i2 = 0, d;
    temp = a;
    while(temp)
    {
        temp /= b;
        i++;
    }
    m = pow(10, i) - 1;
    temp = a;
    while(temp)
    {
        d = temp % b;
        m = m - (9-d)*pow(10,i2);
        i2++;
        temp /= b;
    }
    return m;
}

int main(int argc, const char * argv[]) {
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) != 2)
    {
        printf("input error\n");
        return 1;
    }
    printf("%d\n", transfer(num1, num2));
    return 0;
}
