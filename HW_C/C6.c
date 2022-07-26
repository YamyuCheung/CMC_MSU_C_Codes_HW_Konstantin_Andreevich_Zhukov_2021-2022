//
//  C6.c
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

int fms(int **A, int N, int M)
{
    int i, j, max = 0;
    for (j = 0; j < M; j++)
    {
        int sum = 0;
        for (i = 0; i < N; i++)
            sum += A[i][j];
        if (j == 0)
            max = sum;
        else
            if (sum > max)
                max = sum;
    }
    return max;
}

int main(int argc, const char * argv[])
{
    int **A;
    int i, j, N, M;
    scanf("%d %d", &N, &M);
    A = (int**)malloc(N*sizeof(int*));
    if (A == NULL)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }
    for (i = 0; i < N; i++)
    {
        A[i] = (int*)malloc(M*sizeof(int));
        if (A[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(A[j]);
            free(A);
            printf("Failed to allocate memory\n");
            return 1;
        }
    }
    for (i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            scanf("%d", A[i]+j);

    printf("%d\n", fms(A, N, M));

    for ( i = 0; i < N; i++)
        free(A[i]);
    free(A);
    A = NULL;

    return 0;
}
