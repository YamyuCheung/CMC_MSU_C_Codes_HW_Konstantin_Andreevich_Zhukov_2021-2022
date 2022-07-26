//
//  B18.c
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

void fimin(int * fm, int s)
{
    int i, min1 = -1, min2 = -1;
    
    for (i = 0; i < s; i++)
    {
        if (min1 == -1 || fm[min1] > fm[i])
            min1 = i;
    }
    
    for (i = 0; i < s; i++)
    {
        if (min2 == -1 || fm[min2] > fm[i])
            if (i != min1)
                min2 = i;
    }
    if (min1 < min2)
        printf("%d %d\n", min1, min2);
    else
        printf("%d %d\n", min2, min1);
}


int main(int argc, const char * argv[]) {
    enum {size = 30};
    int i, findmin[size];
    for(i = 0; i < size; i++)
    {
        scanf("%d", findmin+i);
    }
    fimin(findmin, size);
    return 0;
}
