//
//  B19.c
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
double max_array(double * a, int n)
{
    int i, imax = 0;
    for (i = 0; i < n; i++)
    {
        if (a[imax] < a[i])
            imax = i;
    }
    return a[imax];
}

double min_array(double * a, int n)
{
    int i, imin = 0;
    for (i = 0; i < n; i++)
    {
        if (a[imin] > a[i])
            imin = i;
    }
    return a[imin];
}

double max_abs_array(double * a, int n)
{
    double aisarray[n];
    int i, aimax = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            aisarray[i] = a[i];
        else
            aisarray[i] = -a[i];
    }
    for (i = 0; i < n; i+=2)
    {
        if (aisarray[aimax] < aisarray[i])
            aimax = i;
    }
    return aisarray[aimax];
    
}

double min_abs_array(double * a, int n)
{
    double aisarray[n];
    int i, aimin = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            aisarray[i] = a[i];
        else
            aisarray[i] = -a[i];
    }
    for (i = 1; i < n; i+=2)
    {
        if (aisarray[aimin] > aisarray[i])
            aimin = i;
    }
    return aisarray[aimin];
}

double max_min_array(double * a, int n)
{
    int i, imax = 0, imin = 1;
    double sum;
    for (i = 0; i < n; i+=2)
    {
        if (a[imax] < a[i])
            imax = i;
    }
    for (i = 1; i < n; i+=2)
    {
        if (a[imin] > a[i])
            imin = i;
    }
    sum = a[imax] + a[imin];
     
    return sum;
}

double sum_array(double * a, int n)
{
    double sum = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        sum+=a[i];
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    enum {size = 11};
    double isarray[size];
    int i, n;
    for (i = 0; i < size; i++)
    {
        scanf("%lf", isarray+i);
    }
    n = size-1;
    if (isarray[size-1] == 0)
        printf("%g\n", max_array(isarray, n));
    else if (isarray[size-1] == 1)
        printf("%g\n", min_array(isarray, n));
    else if (isarray[size-1] == 2)
        printf("%g\n", max_abs_array(isarray, n));
    else if (isarray[size-1] == 3)
        printf("%g\n", min_abs_array(isarray, n));
    else if (isarray[size-1] == 4)
        printf("%g\n", max_min_array(isarray, n));
    else if (isarray[size-1] == 5)
        printf("%g\n", sum_array(isarray, n));
    else
        printf("-1\n");
    
    return 0;
}
