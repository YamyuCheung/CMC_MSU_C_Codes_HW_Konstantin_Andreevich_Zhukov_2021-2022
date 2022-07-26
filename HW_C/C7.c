//
//  C7.c
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
int chg_row(float **A, int M, int N)
{
    int imi = 0, imj = 0, i, j;
    float *chgrow;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (A[imi][imj] < A[i][j])
            {
                imi = i;
                imj = j;
            }
        }
    }
    
    
    chgrow = (float*)malloc(N*sizeof(float));
    if (chgrow == NULL)
    {
        printf("failed to allocate memory\n");
        return 1;
    }
    for (j = 0; j < N; j++)
    {
        chgrow[j] = A[0][j];
    }
    for (j = 0; j < N; j++)
    {
        A[0][j] = A[imi][j];
    }
    for (j = 0; j < N; j++)
    {
        A[imi][j] = chgrow[j];
    }
    free(chgrow);
    chgrow = NULL;
    return 0;
}

int chg_col(float **A, int M, int N)
{
    int imj = 0, j;
    float *chgcol;
    for (j = 0; j < N; j++)
    {
        if (A[0][imj] < A[0][j])
        {
            imj = j;
        }
    }
    
    
    chgcol = (float*)malloc(N*sizeof(float));
    if (chgcol == NULL)
    {
        printf("failed to allocate memory\n");
        return 1;
    }
    
    for (j = 0; j < M; j++)
    {
        chgcol[j] = A[j][0];
    }
    for (j = 0; j < M; j++)
    {
        A[j][0] = A[j][imj];
    }
    for(j = 0; j < M; j++)
    {
        A[j][imj] = chgcol[j];
    }
    free(chgcol);
    chgcol = NULL;
    return 0;
}

int main(int argc, const char * argv[]) {
    int row, col, counter1, counter2;
    float **isarrchgmax;
    scanf("%d %d", &row, &col);
    isarrchgmax = (float**)malloc(row*sizeof(float*));
    if (isarrchgmax == NULL)
    {
        printf("failed to allocate memory\n");
        return 1;
    }
    for (counter1 = 0; counter1 < row; counter1++)
    {
        isarrchgmax[counter1] = (float*)malloc(col*sizeof(float));
        if (isarrchgmax[counter1] == NULL)
        {
            for (counter2 = 0; counter2 < counter1; counter2++)
                free(isarrchgmax[counter2]);
            free(isarrchgmax);
            printf("Failed to allocate memory\n");
            return 1;
        }
    }
    for (counter1 = 0; counter1 < row; counter1++)
    {
        for (counter2 = 0; counter2 < col; counter2++)
        {
            scanf("%f", isarrchgmax[counter1]+counter2);
        }
    }
    
    chg_row(isarrchgmax, row, col);
    chg_col(isarrchgmax, row, col);
    
    for (counter1 = 0; counter1 < row; counter1++)
    {
        for(counter2 = 0; counter2 < col; counter2++)
        {
            printf("%g ", isarrchgmax[counter1][counter2]);
        }
        printf("\n");
    }
    

    return 0;
}
