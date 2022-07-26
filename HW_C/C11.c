//
//  C11.c
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
#include <string.h>
char thelastsym(const char *str1)
{
    int i;
    char sym = 0;
    for(i = 0; str1[i]; i++)
    {
        sym = str1[i];
    }
    return sym;
}
void pn(const char *str1, char tls)
{
    for (int i = 0; str1[i]; i++)
    {
        if (str1[i] == tls && str1[i+1])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    char str1[1000], tls;
    scanf("%999[^\n]s", str1);
    tls = thelastsym(str1);
    pn(str1, tls);
    
    return 0;
}
