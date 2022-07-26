//
//  B4.c
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
int sum(int num)
{
    int temp, summ=0,d;
    temp = num;
    while(temp)
    {
        d = temp%10;
        summ = summ + d;
        temp /= 10;
    }
    if (summ%2 == 0)
        return 1;
    else
        return 0;
}

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    if (sum(num))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
