//
//  С2.c
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
    int num = 8, count = 0, j = 0, *arr;
    arr = (int*)malloc(num*sizeof(int));
    if (arr == NULL)
    {
        printf("Error: no memory\n");
        return 1;
    }
    
    
    while(scanf("%d", arr+count) != EOF)
    {
        count++;
        if (count == num)
        {
            int *buf;
            num*=2;
            buf = realloc(arr, num*sizeof(int));
            if (buf == NULL)
            {
                printf("Error: no memory\n");
                num/=2;
                break;
            }
            else
                arr = buf;
        }
    }
    for (j = count-1; j >= 0; j--)
        printf("%d ", arr[j]);
    printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}
