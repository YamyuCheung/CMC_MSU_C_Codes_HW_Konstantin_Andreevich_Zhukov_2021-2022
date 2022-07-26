//
//  B12.c
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

int main(int argc, const char * argv[]) {
    enum {size = 12};
    int i, change[size] = {0}, temp;
    for (i = 0; i < size; i++)
    {
        scanf("%d", change+i);
    }
    
    for (i = 0; i <= 8; i+=4)
    {
            temp = change[i];
            change[i] = change[i+3];
            change[i+3] = temp;
            temp = change[i+2];
            change[i+2] = change[i+1];
            change[i+1] = temp;
    }
    
    for (i = 0; i < size; i++)
    {
        printf("%d ", change[i]);
    }
    printf("\n");
    return 0;
}
