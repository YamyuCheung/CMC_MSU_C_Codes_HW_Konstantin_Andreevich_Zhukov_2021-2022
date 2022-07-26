//
//  A20.c
//  c
//
//  Created by Xinyu Zhang on 13.09.2021.
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
enum month {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

int main(int argc, const char * argv[]) {
    int m;
    enum month current_month;
    scanf("%d", &m);
    current_month = m;
    switch (current_month) {
        case jan:
        case mar:
        case may:
        case jul:
        case aug:
        case oct:
        case dec:
            printf("31\n");
            break;
        case feb:
            printf("28\n");
            break;
        case apr:
        case jun:
        case sep:
        case nov:
            printf("30\n");
            break;
            
        default:
            printf("-1\n");
            break;
    }
    return 0;
}
