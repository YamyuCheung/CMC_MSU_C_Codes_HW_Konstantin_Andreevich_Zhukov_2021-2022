//
//  С17.c
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
#define max 20
struct colour{
    char name[20];
    int counter;
};
int add_element(struct colour *clm, char *buf, int *num);

int main(int argc, const char *argv[])
{
    struct colour c[max];
    char temp[20];
    int num_colours = 0, i;
    
    while (scanf("%19s", temp) != EOF)
    {
        int exist = 0;
        for (i = 0; i < num_colours; i++)
        {
            if (!strcmp(c[i].name, temp))
            {
                c[i].counter++;
                exist = 1;
            }
        }
        if (exist == 0)
        {
            if (add_element(c+num_colours, temp, &num_colours) == 1)
            break;
        }
    }
    
    for(i = 0; i < num_colours; i++)
    {
        printf("%s %d\n", c[i].name, c[i].counter);
    }
    

    return 0;
}
int add_element(struct colour *clm, char *buf, int *num)
{
    if (*num >= max)
    {
        return 1;
    }
    strcpy(clm->name, buf);
    clm->counter = 1;
    (*num)++;
    return 0;
}
