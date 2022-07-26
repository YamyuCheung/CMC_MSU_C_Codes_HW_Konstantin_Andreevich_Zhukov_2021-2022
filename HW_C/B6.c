//
//  B6.c
//  c
//
//  Created by Xinyu Zhang on 18.09.2021.
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

int mult(int a, int b)
{
    int res1;
    res1 = a * b;
    return res1;
}

int sum(int a, int b)
{
    int res2;
    res2 = a + b;
    return res2;
}

int main(int argc, const char * argv[]) {
    int a=0, b=0, result=0, corresult, flag = 0, i=0, j=0, k=0, l=0, m=0, a1=0;
    char s1 = ' ', s2 = ' ', ch;
    do{
        scanf("%c", &ch);
        if (ch >= '0' && ch <= '9' && flag == 0)
        {
            a = a*10 + ch - '0';
            i++;
            continue;
        }
        
        
        if (ch == '+' && flag == 0)
        {
            s1 = ch;
            flag = 1;
            continue;
        }
        else if (ch == '*' && flag == 0)
        {
            s1 = ch;
            flag = 1;
            continue;
        }
        else if ((ch < '0' || ch > '9') && (flag == 0) && (ch != '+' || ch != '*'))
        {
            s1 = '^';
            flag = 1;
            continue;
        }
        
        if (ch >= '0' && ch <= '9' && flag == 1)
        {
            b = b*10 + ch - '0';
            j++;
            continue;
        }
        
        
        if (ch == '=' && flag == 1)
        {
            s2 = '=';
            flag = 2;
            continue;
        }
        else if (ch != '=' && (ch < '0' || ch > '9') && flag == 1)
        {
            s2 = '&';
            flag = 2;
        }
        
        
        if (ch >= '0' && ch <= '9' && flag == 2)
        {
            result = result*10 + ch - '0';
            k++;
            continue;
        }
        else if ((ch <'0' || ch > '9') && flag == 2)
        {
            if (!k)
                result = 0;
            if (ch != '\n')
            {
                flag = 3;
            }
            break;
        }
            
    }while(ch != '\n');
//    printf("%d %d %d\n", a, b, result);
//    printf("%c %c\n", s1, s2);
//    printf("%d\n", flag);
//    printf("%d %d %d\n", i, j, k);
    while(1)
    {
        if (i > 0 && s1 == '^')
        {
            printf("WRONG SIGN\n");
            break;
        }
        else if (i > 0 && j > 0 && s1 != '^' && s2 != '=')
        {
            printf("NO EQUAL SIGN\n");
            break;
        }
        else if (i > 0 && j > 0 && k == 0 && s1 != '^' && s2 == '=')
        {
            printf("NO ANSWER\n");
            break;
        }
        else if (i > 0 && j > 0 && k > 0 && s1 != '^' && s2 == '=' && flag == 2)
        {
            if (s1 == '+')
            {
                corresult = sum(a, b);
                if (result == corresult)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            if (s1 == '*')
            {
                corresult = mult(a, b);
                if (result == corresult)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            break;
        }
        else
        {
            printf("INPUT ERROR\n");
            break;
        }
        
        
    }
    
    
    return 0;
}
