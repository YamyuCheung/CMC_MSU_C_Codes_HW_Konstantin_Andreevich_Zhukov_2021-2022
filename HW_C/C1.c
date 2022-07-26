//
//  C1.c
//  c
//
//  Created by Xinyu Zhang on 04.10.2021.
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

int main(int argc, const char * argv[]) {
    int *A, *B, i, N, count = 0;
    scanf("%d", &N);
    A = (int*)malloc(N*sizeof(int));
    if (A == NULL)
    {
        printf("Error: no memory");
        return 1;
    }
    for (i = 0; i < N; i++)
        scanf("%d", A+i);
    for (i = 0; i < N; i++)
        if ((A[i]/10)%10 == 0)
            count++;
    if (count != 0)
    {
        B = (int*)malloc(count*sizeof(int));
        if (B == NULL)
        {
            printf("Error: no memory");
            return 0;
        }
        count = 0;
        for(i = 0; i < N; i++)
            if((A[i]/10)%10 == 0)
                B[count++] = A[i];
        
        for(i = 0; i < count; i++)
            printf("%d ", B[i]);
        printf("\n");
        free(B);
        B = NULL;
    }
    
    free(A);
    A = NULL;
    

    return 0;
}
