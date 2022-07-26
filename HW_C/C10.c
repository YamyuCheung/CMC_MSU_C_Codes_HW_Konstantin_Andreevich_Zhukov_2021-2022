//
//  C10.c
//  c
//
//  Created by Xinyu Zhang on 12.10.2021.
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
//
#include <stdio.h>
#include <stdlib.h>
void printstr(char *str, int N)
{
    int flag = 0, i;
    for (i = 0; i < N; i++)
    {
        if (i%2 == 0)
        {
            str[i] = 'A' + i/2;
        }
        else
        {
            if (flag == 0)
            {
                str[i] = '2';
                flag++;
            }
            else if (flag == 1)
            {
                str[i] = '4';
                flag++;
            }
            else if (flag == 2)
            {
                str[i] = '6';
                flag++;
            }
            else if (flag == 3)
            {
                str[i] = '8';
                flag = 0;
            }
        }
    }
    str[i] = '\0';
}

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    char str[N];
    printstr(str, N);
    
    printf("%s\n", str);
    return 0;
}
