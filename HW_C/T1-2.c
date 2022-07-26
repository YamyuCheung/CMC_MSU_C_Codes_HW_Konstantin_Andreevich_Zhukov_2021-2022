//
//  T1-2.c
//  c
//
//  Created by Xinyu Zhang on 01/11/2021.
//
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

int alternation(int *arr, int n)
{
    int i;
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    for (i = 0; i < n-1; i++)
    {
        if (arr[i]*arr[i+1] >= 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[])
{
    int A[100];
    int i, N;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", A+i);
    }
    if (alternation(A, N))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    
    return 0;
}
