//
//  C18.c
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
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct vector
{
    double x;
    double y;
    double z;
};

double area_of_parallelogram(struct vector * a, struct vector * b)
{
    double ax, ay, az, bx, by, bz, area = 0;
    ax = a->x;
    ay = a->y;
    az = a->z;
    bx = b->x;
    by = b->y;
    bz = b->z;
    area = sqrt(pow((ay*bz-az*by), 2)+pow((az*bx-ax*bz), 2)+pow((ax*by-ay*bx), 2));


    return area;
}

int main(int argc, const char * argv[]) {
    enum {size = 2};
    struct vector calc[size];
    int counter;
    for (counter = 0; counter < size; counter++)
    {
        scanf("%lf %lf %lf", &calc[counter].x, &calc[counter].y, &calc[counter].z);
    }
    printf("%.4lf\n", area_of_parallelogram(calc, calc+1));

    return 0;
}
