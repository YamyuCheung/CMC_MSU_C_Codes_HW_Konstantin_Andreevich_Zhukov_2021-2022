//
//  B20.c
//  c
//
//  Created by Xinyu Zhang on 01.10.2021.
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
enum {col = 10, row = 10};
int sum_max(int (*A)[col], int row)
{
    int sum = 0, i, j;
    for (i = 0; i < row; i++)
    {
        int jmax = 0;
        for (j = 0; j < col; j++)
            if (A[i][j] > A[i][jmax])
                jmax = j;
        sum += A[i][jmax];
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    int B[row][col], i, j;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", B[i]+j);        }
    }

    printf("%d", sum_max(B,row));
}
