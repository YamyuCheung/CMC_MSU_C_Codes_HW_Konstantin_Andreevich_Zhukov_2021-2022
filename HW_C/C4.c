//
//  C4.c
//  c
//
//  Created by Xinyu Zhang on 04.10.2021.
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

void print_digit(char str[])
{
    int counter1 = 0, *carr, counter2 = 0, nmax = 0, temp;

    while(str[counter1] != '\0')
    {
        if (str[counter1] >= '0' && str[counter1] <= '9')
        {
            temp = str[counter1] - '0';
            if (temp > nmax)
            {
                nmax = temp;
            }
        }
        counter1++;
    }

    carr = (int*)malloc(nmax*sizeof(int));
//    if (carr == NULL)
//    {
//        printf("Failed to allocate memory\n");
//    }
    for (counter2 = 0; counter2 <= nmax; counter2++)
    {
        carr[counter2] = 0;
    }

    counter1 = 0;

    while(str[counter1] != '\0')
    {
        if (str[counter1] >= '0' && str[counter1] <= '9')
        {
            counter2 = str[counter1] - '0';
            carr[counter2]++;
        }
        counter1++;
    }

    for(counter2 = 0; counter2 <= nmax; counter2++)
    {
        if (carr[counter2] != 0)
        {
            printf("%d %d\n", counter2, carr[counter2]);
        }
    }
    free(carr);
    carr = NULL;

}

int main(int argc, const char * argv[]) {
    int N = 8, count = 0;
    char *str;
    str = (char*)malloc(N*sizeof(char));
    if (str == NULL)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }
    while(scanf("%c", str+count) != EOF)
    {
        count++;
        if (count == N)
        {
            char *buf;
            N*=2;
            buf = realloc(str, N*sizeof(char));
            if (buf == NULL)
            {
                printf("Failed to allocate memory\n");
                N/=2;
                break;
            }
            else
                str = buf;
        }
    }

    print_digit(str);
    free(str);
    str = NULL;



    return 0;
}
