//
//  C24.c
//  c
//
//  Created by Xinyu Zhang on 29/10/2021.
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
    FILE *f1, *f2;
    char n, i;
    int ch;
    if (argc < 4)
    {
        fprintf(stderr, "no filenames input\n");
        return 1;
    }
    f1 = fopen(argv[1], "r");
    if (f1 == NULL)
    {
        fprintf(stderr, "Could't open file %s\n", argv[1]);
        return 2;
    }
    f2 = fopen(argv[2], "w");
    if (f2 == NULL)
    {
        fprintf(stderr, "Could't open file %s\n", argv[2]);
        fclose(f1);
        return 2;
    }
    n = atoi(argv[3]);
    if ((n == 0 && argv[3][0] != '0') || n < 0)
    {
        fprintf(stderr, "wrong n\n");
        fclose(f1);
        fclose(f2);
        return 3;
    }
    i = 0;
    while ((ch = fgetc(f1)) != EOF && i < n)
    {
        if (ch == '\n')
        {
            i++;
        }
        fputc(ch, f2);
    }
    // while(fgets=(str, 51, f1) != NULL && i < n)
    // {
    //     i++;
    //     fputs(str, f2);
    // }
    fclose(f1);
    fclose(f2);

    return 0;
}
