//
//  B11.c
//  c
//
//  Created by Xinyu Zhang on 24.09.2021.
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
#define SIZE 10

int main(int argc, const char * argv[]) {
    int i, Arr[SIZE] = {0};
    int imax, imin;
    for (i = 0; i<SIZE; i++)
        scanf("%d", Arr+i);
    imax = imin = 0;
    for (i = 0; i<SIZE; i++)
    {
        if(Arr[i]>Arr[imax])
            imax = i;
        if(Arr[i]<Arr[imin])
            imin = i;
    }
    printf("%d %d %d %d\n", imax+1, Arr[imax], imin+1, Arr[imin]);
    return 0;
}
