//
//  C26.c
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
    enum {maxnum = 59};
    FILE *f1, *f2;
    int counter = 0, counter2 = 0, counter3 = 0, counter4 = 0, *saverows;
    char ch, flag = 0;
    if (argc < 3)
    {
        fprintf(stderr, "Error\n");
        return 1;
    }
    f1 = fopen(argv[1], "r");
    if (f1 == NULL)
    {
        fprintf(stderr, "Error\n");
        return 1;
    }
    f2 = fopen(argv[2], "w");
    if (f2 == NULL)
    {
        fprintf(stderr, "Error\n");
        fclose(f1);
        return 1;
    }

    

    while ((ch = fgetc(f1)) != EOF)
    {
        if (ch != '\n')
        {
            counter++;
        }
        else if (ch == '\n')
        {
            if (counter > maxnum)
            {
                counter2++;
            }
            counter = 0;
        }
    }

    saverows = (int*)malloc(counter2*sizeof(int));
    if (saverows == NULL)
    {
        fprintf(stderr, "Error\n");
        return 1;
    }
    fseek(f1, sizeof(f1)-8, SEEK_SET);

    counter = 0;
    while ((ch = fgetc(f1)) != EOF)
    {
        if (ch != '\n')
        {
            counter++;
        }
        else if (ch == '\n')
        {
            counter3++;
            if (counter > maxnum)
            {
                saverows[counter4] = counter3;
                counter4++;
            }
            counter = 0;
        }
    }
    
    
    
//    printf("%d\n", counter3);
//    for (counter4 = 0; counter4 < counter2; counter4++)
//    {
//        printf("%d\n", saverows[counter4]);
//    }

    fseek(f1, sizeof(f1)-8, SEEK_SET);
    counter = 1;
    while ((ch = fgetc(f1)) != EOF)
    {
        for(counter4 = 0; counter4 < counter2; counter4++)
        {
            if (counter == saverows[counter4])
            {
                flag = 1;
            }
        }

        if (ch != '\n' && flag == 0)
        {
            fputc(ch, f2);
        }
        else if (ch == '\n')
        {
            if (flag == 0)
            {
                fputc('\n', f2);
            }
            counter++;
            flag = 0;
        }
    }
    

    free(saverows);
    saverows = NULL;
    fclose(f1);
    fclose(f2);
    
    return 0;
}
