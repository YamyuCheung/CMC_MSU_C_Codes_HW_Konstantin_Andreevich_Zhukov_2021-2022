//
//  T1-4.c
//  c
//
//  Created by Xinyu Zhang on 01/11/2021.
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
#include <math.h>
#include <stdlib.h>

struct circle
{
    double p[2];
    double r;
};

int intersection(struct circle *pc1, struct circle *pc2)
{
    double d, dx, dy;
    dx = pc1->p[0] - pc2->p[0];
    dy = pc1->p[1] - pc2->p[1];
    d = sqrt(dx*dx + dy*dy);
    if (d <= pc1->r + pc2->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main(int argc, const char * argv[])
{
    FILE *f = NULL;
    struct circle c1, c2;
    if (argc < 2)
    {
        fprintf(stderr, "Error\n");
        return 1;
    }
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "Error\n");
        return 2;
    }
    if (fscanf(f, "%lf %lf %lf", &c1.p[0], &c1.p[1], &c1.r) != 3)
    {
        fprintf(stderr, "Error\n");
        fclose(f);
        return 3;
    }
    if (fscanf(f, "%lf %lf %lf", &c2.p[0], &c2.p[1], &c2.r) != 3)
    {
        fprintf(stderr, "Error\n");
        fclose(f);
        return 3;
    }
    if (c1.r <= 0 || c2.r <= 0)
    {
        fprintf(stderr, "Error\n");
        fclose(f);
        return 4;
    }
    if (intersection(&c1, &c2))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    fclose(f);
    
    return 0;
}
