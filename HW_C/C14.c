//
//  C14.c
//  c
//
//  Created by Xinyu Zhang on 16.10.2021.
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int calc = 0, counter = 0, counter2 = 0;
    long N;
    N = strlen(argv[1]);
    char *str, *str2;
    str = (char*)malloc(N*sizeof(char));
    strcpy(str, argv[1]);
    for (counter = 0; counter < N; counter++)
    {
        if (str[counter])
        {
            calc++;
        }
    }
    str2 = (char*)malloc(N*sizeof(char));
    for (counter = calc-1; counter >= 0; counter--)
    {
        str2[counter2] = str[counter];
        counter2++;
    }
    str2[counter2] = '\0';
    
    printf("%s\n", str2);
    free(str);
    str = NULL;
    free(str2);
    str2 = NULL;
    return 0;
}
