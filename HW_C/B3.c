//
//  B3.c
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
#define pi 3.1415926536

int nf(int n)
{
    int temp, i;
    temp = n;
    if (n != 0)
    {
        for (i=n-1; i>0; i--)
        {
            temp = temp * i;
        }
    }
    else temp = 1;
    
    return temp;
}

float cosinus(float x)
{
    float res = 0;
    int i=4, n;
    n = 6;
    for(i=0; i<=n; i++)
    {
    res = res + pow(-1, i)*pow(x, 2*i)/nf(2*i);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    float x;
    scanf("%f", &x);
    if (x > 180)
        x -= 360;
    if (x < -180)
        x += 360;
    x = x*(pi/180);
    printf("%.3f\n", cosinus(x));
    return 0;
}
