//
//  B17.c
//  c
//
//  Created by Xinyu Zhang on 28.09.2021.
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

int calc(int * A, int num)
{
    int cnum = 0, i, imax = 0, temp;
    for (i = 0; i < num; i++)
    {
        if(A[imax] < A[i])
            imax = i;
    }
    for (i = 0; i < num; i++)
    {
        if (A[i] < 0)
        {
            temp = -A[i];
            if (temp > A[imax])
                cnum++;
        }
    }
    
    return cnum;
}

int main(int argc, const char * argv[]) {
    enum {size = 10};
    int anum[size], i;
    for(i = 0; i < size; i++)
    {
        scanf("%d", anum+i);
    }
    printf("%d\n", calc(anum, size));
    return 0;
}
