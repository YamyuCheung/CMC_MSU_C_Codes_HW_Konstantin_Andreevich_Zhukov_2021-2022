//
//  C8.c
//  c
//
//  Created by Xinyu Zhang on 08.10.2021.
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
void createarr(int **A, int N)
{
    int i, j, n = 1, counter;
    for (counter = 0; counter <= N/2; counter++)
    {
        for (j = counter; j <= N-counter-1; j++)
        {
            A[counter][j] = n++;
        }
        for (i = counter+1; i < N-counter; i++)
        {
            A[i][N-counter-1] = n++;
        }
        for (j = N-counter-2; j > counter; j--)
        {
            A[N-counter-1][j] = n++;
        }
        for (i = N-counter-1; i > counter; i--)
            A[i][counter] = n++;
    }
}
 
int main(int argc, const char * argv[]) {
    int **cyclearr, N, counter1, counter2;
    scanf("%d", &N);
    cyclearr = (int**)malloc(N*sizeof(int*));
    if (cyclearr == NULL)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }
    for (counter1 = 0; counter1 < N; counter1++)
    {
        cyclearr[counter1] = (int*)malloc(N*sizeof(int));
        if (cyclearr[counter1] == NULL)
        {
            for (counter2 = 0; counter2 < counter1; counter2++)
            {
                free(cyclearr[counter2]);
            }
            free(cyclearr);
            printf("Failed to allocate memory\n");
            return 1;
        }
    }
    createarr(cyclearr, N);
    
    for (counter1 = 0; counter1 < N; counter1++)
    {
        for (counter2 = 0; counter2 < N; counter2++)
        {
            printf("%d ", cyclearr[counter1][counter2]);
        }
        printf("\n");
    }
    free(cyclearr);
    cyclearr = NULL;

    return 0;
}
