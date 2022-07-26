//
//  B15.c
//  c
//
//  Created by Xinyu Zhang on 25.09.2021.
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

#include<stdio.h>

int getmaxnum(int a[], int num)
{
    int i, maxi = 0;

    for(i = 0; i <= num; i++)
    {
        if(a[maxi] < a[i])
            maxi = i;
    }

    return maxi;
}

long long changenum(long long num)
{
    enum {size = 11};
    int i, changar[size], gmi = 0, rsize = 0, mia, temp;
    for (i = 0; i < size; i++)
    {
        changar[i] = -1;
    }
    for (rsize = 0; rsize < size; rsize++)
    {
        if (num >= 10)
        {
            changar[rsize] = num%10;
            num/=10;
        }
        else
        {
            changar[rsize] = (int)num;
            break;
        }
    }
    
    
    for(gmi = rsize; gmi >= 0; gmi--)
    {
        mia = getmaxnum(changar, gmi);
        if(mia != gmi && changar[mia] != changar[gmi])
        {
            temp = changar[mia];
            changar[mia] = changar[gmi];
            changar[gmi]= temp;
            break;
        }
    }



    int x = 0;
    for(i = rsize; i >= 0; i--)
    {
        x*=10;
        x = changar[i]+x;
    }
    return x;
}

int main(int argc, const char * argv[]) {
    long long num, cnum;
    scanf("%lld", &num);
    cnum = changenum(num);
    printf("%lld\n", cnum);
    return 0;
}

