//
//  C16.c
//  c
//
//  Created by Xinyu Zhang on 18.10.2021.
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
#include <string.h>

struct colour
{
    char name[20];
    int counter;
};

int main(int argc, const char *argv[])
{
    struct colour white = {"WHITE", 0};
    struct colour black = {"BLACK", 0};
    struct colour other = {"OTHER", 0};
    char temp[20];
    
    while (scanf("%19s", temp) != EOF)
    {
        if (!strcmp(white.name, temp))
        {
            white.counter++;
        }
        else if (!strcmp(black.name, temp))
        {
            black.counter++;
        }
        else
        {
            other.counter++;
        }
    }
    
    printf("%s %d\n", white.name, white.counter);
    printf("%s %d\n", black.name, black.counter);
    printf("%s %d\n", other.name, other.counter);
    
    

    return 0;
}
