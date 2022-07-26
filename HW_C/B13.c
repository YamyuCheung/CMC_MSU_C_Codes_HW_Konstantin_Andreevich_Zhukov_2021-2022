//
//  B13.c
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
    enum {size = 10};
    int updown[size] = {0}, i, j, temp;
    for (i = 0; i < size; i++)
    {
        scanf("%d", updown+i);
    }

    for(i = 0; i < size; i++)
    {
        for (j = 0; j < size/2-i-1; j++)
        {
            if (updown[j] > updown[j+1])
            {
                temp = updown[j];
                updown[j] = updown[j+1];
                updown[j+1] = temp;
            }
        }
    }

    for(i = 0; i < size; i++)
    {
        for (j = 5; j < size-i-1; j++)
        {
            if (updown[j] < updown[j+1])
            {
                temp = updown[j];
                updown[j] = updown[j+1];
                updown[j+1] = temp;
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        printf("%d ", updown[i]);
    }
    printf("\n");
    return 0;
}
