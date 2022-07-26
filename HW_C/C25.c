//
//  C25.c
//  c
//
//  Created by Xinyu Zhang on 30/10/2021.
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

int main(int argc, const char * argv[])
{
    FILE *f;
    int ch, sum = 0, temp;
    if (argc < 2)
    {
        fprintf(stderr, "-1\n");
        return 1;
    }
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "-1\n");
        return 1;
    }
    while ((ch = fgetc(f))!=EOF)
    {
        if (ch >= '0' && ch <= '9')
        {
            ch = ch - '0';
            sum+=ch;
        }
        else if (ch >= 'A' && ch <= 'F')
        {
            temp = ch - 'A';
            sum = 10+temp+sum;
        }
        else if (ch >= 'a' && ch <= 'f')
        {
            temp = ch - 'a';
            sum = 10+temp+sum;
        }
    }
    printf("%d\n", sum);
    
    fclose(f);
    
    return 0;
}
