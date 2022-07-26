//
//  C15.c
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
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    if (argc < 4)
    {
        printf("-1\n");
        return 1;
    }
    int counter1, counter2, temp3a = 0, nlenth = 0, flag = 0, nwidth, a, b;
    long long **isarr, temp3, temp1, temp2, width;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    nwidth = atoi(argv[3]);
    if (a == 0)
    {
        if (strcmp("0", argv[1]))
        {
            printf("-1\n");
            return 1;
        }
    }
    if (b == 0)
    {
        if (strcmp("0", argv[2]))
        {
            printf("-1\n");
            return 1;
        }
    }
    if (nwidth == 0)
    {
        if (strcmp("0", argv[3]))
        {
            printf("-1\n");
            return 1;
        }
    }
    temp1 = a;
    temp2 = a;
    if (a >= b)
    {
        printf("-1\n");
        return 1;
    }
    if (nwidth <= 0)
    {
        printf("-1\n");
        return 1;
    }
    width = b-a+1;
    isarr = (long long**)malloc(width*sizeof(long long*));
    if (isarr == NULL)
    {
        printf("-1\n");
        return 1;
    }

    for (counter1 = 0; counter1 < width; counter1++)
    {
        isarr[counter1] = (long long*)malloc(width*sizeof(long long));
        if (isarr[counter1] == NULL)
        {
            for (counter2 = 0; counter2 < counter1; counter2++)
            {
                free(isarr[counter2]);
            }
            free(isarr);
            printf("-1\n");
            return 1;
        }
    }

    for (counter1 = 0; counter1 < width; counter1++)
    {
        for (counter2 = 0; counter2 < width; counter2++)
        {
            isarr[counter1][counter2] = 0;
        }
    }

    for (counter1 = 1; counter1 < width; counter1++)
    {
        isarr[0][counter1] = temp1;
        temp1++;
    }
    for (counter2 = 1; counter2 < width; counter2++)
    {
        isarr[counter2][0] = temp2;
        temp2++;
    }
    for (counter1 = 1; counter1 < width; counter1++)
    {
        for (counter2 = 1; counter2 < width; counter2++)
        {
            isarr[counter1][counter2] = isarr[0][counter1] * isarr[counter2][0];
            temp3 = isarr[counter1][counter2];
            while (temp3)
            {
                if (temp3 > 0)
                {
                    temp3a++;
                    temp3/=10;
                }
                if (temp3 < 0)
                {
                    if (flag == 0)
                    {
                        temp3a++;
                        flag = 1;
                    }
                    temp3a++;
                    temp3/=10;
                }
            }
            if (temp3a > nlenth)
            {
                nlenth = temp3a;
            }
            temp3a = 0;
            flag = 0;
        }
    }

    if (nlenth > nwidth)
    {
        nwidth = nlenth;
    }


    for (counter1 = 0; counter1 < width; counter1++)
    {
        for (counter2 = 0; counter2 < width; counter2++)
        {
            if (counter1 == 0 && counter2 == 0)
            {
                for (int i = 0; i <= nwidth; i++)
                {
                    printf(" ");
                }
            }
            else if (counter2 < width-1)
                printf("%*lld ", nwidth, isarr[counter1][counter2]);
            else if (counter2 == width-1)
                printf("%*lld", nwidth, isarr[counter1][counter2]);
        }
        printf("\n");
    }

    for (counter1 = 0; counter1 < width; counter1++)
    {
        free(isarr[counter1]);
    }
    free(isarr);

    return 0;
}

