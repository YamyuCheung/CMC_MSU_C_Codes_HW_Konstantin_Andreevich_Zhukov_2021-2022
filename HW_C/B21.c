//
//  B21.c
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
enum {col = 5, row = 5};
int mdiag(int (*A)[col], int row)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                sum += A[i][j];
                break;
            }
        }
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    int i, j, inn[row][col];
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            scanf("%d", inn[i]+j);
    }
    printf("%d\n", mdiag(inn, row));
}
