//
//  C23.c
//  c
//
//  Created by Xinyu Zhang on 23.10.2021.
//
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
    char word[20];
    struct lnode *next;
    struct lnode *prev;
};

struct lnode* add_elem(struct lnode *cur, const char *buf)
{

    struct lnode *New;
    New = (struct lnode*)malloc(sizeof(struct lnode));
    if (New == NULL)
    {
        return NULL;
    }
    strcpy(New->word, buf);
    if (cur == NULL)
    {
        New->next = New->prev = NULL;
    }
    else
    {
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = New;
        New->prev = cur;
        New->next = NULL;
    }
    
    return New;
}

void changelist(struct lnode *cur, int rsize)
{
    struct lnode *buf, *ishead = cur;
    int i, j;
    buf = (struct lnode*)malloc(sizeof(struct lnode));
    if (buf == NULL)
    {
        return;
    }
    for (i = 0; i < rsize-1; i++)
    {
        for (j = 0; j < rsize-i-1; j++)
        {
            if (cur == NULL || cur->next == NULL)
            {
                return;
            }
            else if (strcmp(cur->word, cur->next->word) > 0)
            {
                strcpy(buf->word, cur->word);
                strcpy(cur->word, cur->next->word);
                strcpy(cur->next->word, buf->word);
            }
            cur = cur->next;
        }
        cur = ishead;
    }
    free(buf);
    buf = NULL;
    
}

void printflist(struct lnode *cur)
{
    while (cur != NULL)
    {
        printf("%s ", cur->word);
        cur = cur->next;
    }
    printf("\n");
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

int main(int argc, const char * argv[])
{
    struct lnode *head = NULL, *temp = NULL;
    char buf[20], flag = 0;
    int rsize = 0;

    while (scanf("%19s", buf) != EOF)
    {
        temp = add_elem(head, buf);
        if (flag == 0)
        {
            head = temp;
            flag = 1;
        }
        if (temp == NULL)
        {
            return 1;
        }
        rsize++;
    }
    
    
    changelist(head, rsize);

    printflist(head);

    deletelist(head);
    free(head);
    head = NULL;
    return 0;
}
