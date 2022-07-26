//
//  C19.c
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

struct Date
{
    unsigned year;
    unsigned month;
    unsigned day;
};
void resorting(struct Date * st, int length)
{
    int i, j;
    struct Date temp;
    for (i = 0; i < length-1; i++)
    {
        for (j = 0; j < length-i-1; j++)
        {
            if (st[j].year > st[j+1].year)
            {
                temp = st[j];
                st[j] = st[j+1];
                st[j+1] = temp;
            }
        }
    }
    for (i = 0; i < length-1; i++)
    {
        for (j = 0; j < length-i-1; j++)
        {
            if (st[j].month > st[j+1].month)
            {
                if (st[j].year == st[j+1].year)
                {
                    temp = st[j];
                    st[j] = st[j+1];
                    st[j+1] = temp;
                }
            }
        }
    }
    for (i = 0; i < length-1; i++)
    {
        for (j = 0; j < length-i-1; j++)
        {
            if (st[j].day > st[j+1].day)
            {
                if (st[j].year == st[j+1].year && st[j].month == st[j+1].month)
                {
                    temp = st[j];
                    st[j] = st[j+1];
                    st[j+1] = temp;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    enum {size = 20};
    struct Date sorting[size];
    int counter = 0, temp1, temp2, temp3, flag = 0, rsize, monthsny[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, monthsly[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    while (scanf("%d %d %d", &temp1, &temp2, &temp3)!= EOF && counter < size)
    {
        if (temp1 >= 0 && flag == 0)
        {
            sorting[counter].year = temp1;
            flag = 1;
        }
        if (temp2 >= 1 && temp2 <= 12 && flag == 1)
        {
            sorting[counter].month = temp2;
            flag = 2;
        }
        else if (flag == 1)
        {
            flag = 0;
            continue;
        }
        if (temp3 >= 1 && temp3 <= 31 && flag == 2)
        {
            if (temp1%4 == 0)
            {
                if (temp3 <= monthsly[temp2-1])
                {
                    sorting[counter].day = temp3;
                    flag = 0;
                }
                else
                {
                    flag = 0;
                    continue;
                }
            }
            else if (temp1%4)
            {
                if (temp3 <= monthsny[temp2-1])
                {
                    sorting[counter].day = temp3;
                    flag = 0;
                }
                else
                {
                    flag = 0;
                    continue;
                }
            }
        }
        else if (flag == 2)
        {
            flag = 0;
            continue;
        }
        counter++;
        if (counter == size)
        {
            break;
        }
    }
    rsize = counter;
    
    resorting(sorting, rsize);
    
    for (counter = 0; counter < rsize; counter++)
    {
        if (sorting[counter].month < 10 && sorting[counter].day >= 10)
        {
            printf("%u %02u %u\n", sorting[counter].year, sorting[counter].month, sorting[counter].day);
        }
        else if (sorting[counter].month >= 10 && sorting[counter].day < 10)
        {
            printf("%u %u %02u\n", sorting[counter].year, sorting[counter].month, sorting[counter].day);
        }
        else if (sorting[counter].month < 10 && sorting[counter].day < 10)
        {
            printf("%u %02u %02u\n", sorting[counter].year, sorting[counter].month, sorting[counter].day);
        }
        else
        {
        printf("%u %u %u\n", sorting[counter].year, sorting[counter].month, sorting[counter].day);
        }
    }
    
    return 0;
}
