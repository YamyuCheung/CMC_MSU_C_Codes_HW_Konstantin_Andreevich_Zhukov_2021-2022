//
//  C3.c
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
void changearr(long * A, long M)
{
    for (int i = 0; i < M-1; i++)
    {
        for (int j = 0; j < M-i-1; j++)
        {
            if (A[j]%10 > A[j+1]%10)
            {
                long temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    long N, *fibonacci, count;
    scanf("%ld", &N);
    fibonacci = (long*)malloc(N*sizeof(long));
    if (fibonacci == NULL)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (count = 2; count < N; count++)
    {
        fibonacci[count] = fibonacci[count-1] + fibonacci[count-2];
    }
    
    changearr(fibonacci, N);
    
    for (count = 0; count < N; count++)
    {
        printf("%ld ", *(fibonacci+count));
    }
    printf("\n");
    free(fibonacci);
    fibonacci = NULL;
    return 0;
}
