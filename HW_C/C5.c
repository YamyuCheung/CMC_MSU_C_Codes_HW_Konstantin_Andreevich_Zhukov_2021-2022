//
//  C5.c
//  c
//
//  Created by Xinyu Zhang on 05.10.2021.
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

void chgeverythearr(int everytharr[], int size)
{
    int end = size/3 - 1, start = 0;
    while (start < size)
    {
        int temp1 = start, temp2 = end;
        while (start < end)
        {
            int temp = everytharr[start];
            everytharr[start] = everytharr[end];
            everytharr[end] = temp;
            start++;
            end--;
        }
        start = temp1 + size/3;
        end = temp2 + size/3;
    }

}

int main(int argc, const char * argv[]) {
    int *everytharr = NULL, size = 0, rsize = 0, i = 0;


    if (scanf("%d", &size) != ' ')
    {
        if (size == 0)
        {
            printf("-1\n");
            return 1;
        }
        if (size%3 != 0)
        {
            printf("-1\n");
            return 1;
        }
        if (size%3 == 0)
        {
            everytharr = (int*)malloc(size*sizeof(int));
            if (everytharr == NULL)
            {
                printf("-1\n");
                return 1;
            }
        }
    }


    while (scanf("%d", everytharr+i) != EOF)
    {
        i++;
        rsize++;
    }


    if (rsize == size)
    {
        chgeverythearr(everytharr, size);
    }
    else
    {
        printf("-1\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(everytharr+i));
    }
    printf("\n");
    free(everytharr);
    everytharr = NULL;



    return 0;
}
