//
//  B16.c
//  c
//
//  Created by Xinyu Zhang on 27.09.2021.
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


#include <stdio.h>

void chgnum(int * A, int M)
{
    int nim = -1, i;
    for(i = 0; i < M; i++)
    {
        if (A[i] < 0 && (nim == -1 || A[nim] < A[i]))
            nim = i;
    }
    
    if (nim >= 0)
    {
        int temp = A[M-1];
        A[M-1] = A[nim];
        A[nim] = temp;
    }
}


int main(int argc, const char * argv[]) {
    enum {size = 10};
    int chgn[size], i;
    for(i = 0; i < size; i++)
    {
        scanf("%d", chgn+i);
    }
    chgnum(chgn, size);
    for(i = 0; i < size; i++)
    {
        printf("%d ", chgn[i]);
    }
    printf("\n");
}
