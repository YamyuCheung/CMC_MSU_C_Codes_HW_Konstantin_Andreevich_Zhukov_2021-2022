//
//  B22.c
//  c
//
//  Created by Xinyu Zhang on 02.10.2021.
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
enum {row = 11, col = 11};

void changemax(int (*A)[col], int row)
{
    int temp1 = A[0][0], ti1 = 0, tj1 = 0, temp2 = A[0][col-1], ti2 = 0, tj2 = col-1, temp;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                if (A[i][j] > temp1)
                {
                    temp1 = A[i][j];
                    ti1 = i;
                    tj1 = j;
                }
            }
            if (i == col-j-1)
            {
                if(A[i][j] > temp2)
                {
                    temp2 = A[i][j];
                    ti2 = i;
                    tj2 = j;                }
            }
        }
    }
    
    if (temp1 > temp2)
    {
        temp = A[row/2][col/2];
        A[row/2][col/2] = A[ti1][tj1];
        A[ti1][tj1] = temp;
    }
    else if (temp1 < temp2)
    {
        temp = A[row/2][col/2];
        A[row/2][col/2] = A[ti2][tj2];
        A[ti2][tj2]= temp;
    }
    else if (temp1 == temp2)
    {
        if (ti1 < ti2)
        {
            temp = A[row/2][col/2];
            A[row/2][col/2] = A[ti1][tj1];
            A[ti1][tj1] = temp;
        }
        else if (ti1 > ti2)
        {
            temp = A[row/2][col/2];
            A[row/2][col/2] = A[ti2][tj2];
            A[ti2][tj2]= temp;
        }
        else if(ti1 == ti2)
        {
            if (tj1 > tj2)
            {
                temp = A[row/2][col/2];
                A[row/2][col/2] = A[ti2][tj2];
                A[ti2][tj2]= temp;
            }
            else if (tj1 < tj2)
            {
                temp = A[row/2][col/2];
                A[row/2][col/2] = A[ti1][tj1];
                A[ti1][tj1] = temp;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    int i, j, inn[row][col];
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", inn[i]+j);
        }
    }
    
    changemax(inn, col);
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", inn[i][j]);
        }
        printf("\n");
    }
    return 0;
}
