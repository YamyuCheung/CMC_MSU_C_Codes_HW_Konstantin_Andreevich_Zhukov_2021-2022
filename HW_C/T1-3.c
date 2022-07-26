//
//  T1-3.c
//  c
//
//  Created by Xinyu Zhang on 01/11/2021.
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
    int **matr = NULL;
    int *vec = NULL, *res = NULL;
    int row, col, len, i, j;
    
    scanf("%d %d", &row, &col);
    
    matr = (int**)malloc(row*sizeof(int*));
    if (matr == NULL)
    {
        fprintf(stderr, "-1\n");
        return 1;
    }
    for (i = 0; i < row; i++)
    {
        matr[i] = (int*)malloc(col*sizeof(int));
        if (matr[i] == NULL)
        {
            goto FREE_MEM;
        }
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", matr[i]+j);
        }
    }
    
    scanf("%d", &len);
    
    if (col != len)
    {
        goto FREE_MEM;
    }
    
    vec = (int*)malloc(len*sizeof(int));
    if (vec == NULL)
    {
        goto FREE_MEM;
    }
    
    for (i = 0; i < len; i++)
    {
        scanf("%d", vec+i);
    }
    
    res = (int*)malloc(row*sizeof(int));
    
    if (res == NULL)
    {
        goto FREE_MEM;
    }
    for (i = 0; i < row; i++)
    {
        res[i] = 0;
        for(j = 0; j < col; j++)
        {
            res[i]+=matr[i][j]*vec[j];
        }
    }
    
    for (i = 0; i < row; i++)
    {
        printf("%d\n", res[i]);
    }
    goto MEM;
    
    
    
FREE_MEM:
    fprintf(stderr, "-1\n");
MEM:    for (i = 0; i < row; i++)
        {
            free(matr[i]);
        }
    free(matr);
    free(vec);
    free(res);
    matr = NULL;
    vec = NULL;
    res = NULL;
    
    
    
    return 0;
}
