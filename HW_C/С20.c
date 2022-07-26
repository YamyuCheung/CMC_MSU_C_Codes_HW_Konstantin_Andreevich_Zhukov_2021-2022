//
//  С20.c
//  c
//
//  Created by Xinyu Zhang on 22.10.2021.
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

struct lnode
{
    char str[20];
    struct lnode *next;
    struct lnode *prev;
};

int add_elem (struct lnode *cur, const char *buf)
{
    struct lnode *New;
    while (cur->next)
    {
        cur = cur->next;
    }
    New = (struct lnode*)malloc(sizeof(struct lnode));
    if (New == NULL)
    {
        return 1;
    }
    strcpy(New->str, buf);
    New->prev = cur;
    cur->next = New;
    New->next = NULL;
    return 0;
}

void printflist(struct lnode *cur)
{
    while (cur != NULL)
    {
        printf("%s\n", cur->str);
        cur = cur->next;
    }
}

void deletelist(struct lnode *cur)
{
    struct lnode *tmp;
    if (cur == NULL)
    {
        return;
    }
    while (cur->next)
    {
        cur = cur->next;
    }
    while (cur->prev)
    {
        tmp = cur->prev;
        free(cur);
        cur = tmp;
    }
}

void printreverse(struct lnode *cur)
{
    if (cur != NULL)
    {
        while (cur->next)
        {
            cur = cur->next;
        }
        while (cur)
        {
            printf("%s\n", cur->str);
            cur = cur->prev;
        }
    }
}
int main(int argc, const char * argv[])
{
    struct lnode *head = NULL;
    char buf[20];

    head = (struct lnode*)malloc(sizeof(struct lnode));
    if (head == NULL)
    {
        return 1;
    }

    if (scanf("%19s", buf) != EOF)
    {
        strcpy(head->str, buf);
        head->next = head->prev = NULL;
    }

    while (scanf("%19s", buf) != EOF)
    {
        if (add_elem(head, buf))
        {
            printf("Error: can,t add element\n");
            return 1;
        }
    }

    // printflist(head);
    printreverse(head);

    deletelist(head);
    free(head);
    head = NULL;
    return 0;
}
