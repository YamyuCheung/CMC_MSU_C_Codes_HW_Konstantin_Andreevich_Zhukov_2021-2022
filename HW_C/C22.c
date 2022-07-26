//
//  C22.c
//  c
//
//  Created by Xinyu Zhang on 23.10.2021.
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

struct lnode* add_elem(struct lnode *cur, const char *buf)
{

    struct lnode *New;
    New = (struct lnode*)malloc(sizeof(struct lnode));
    if (New == NULL)
    {
        return NULL;
    }
    strcpy(New->str, buf);
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

void printflist(struct lnode *cur)
{
    while (cur != NULL)
    {
        printf("%s ", cur->str);
        cur = cur->next;
    }
    printf("\n");
}

int insert_element(struct lnode *head, const char *find_str, const char *insert_str)
{
    if (head == NULL)
    {
        return 1;
    }
    struct lnode *New, *temp = NULL;
    New = (struct lnode*)malloc(sizeof(struct lnode));
    strcpy(New->str, insert_str);
    while (head != NULL)
    {
        if (strcmp(head->str, find_str) == 0)
        {
            New->next = head->next;
            New->prev = head;
            head->next = New;
        }
        temp = head;
        head = head->next;
    }
    return 0;
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
    
    if (argc < 3)
    {
        return 1;
    }

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
    }
    
    if (head == NULL)
    {
        return 1;
    }
    
//    for (int i = 1; i < argc-1; i++)
//    {
        insert_element(head, argv[1], argv[2]);
//    }

    printflist(head);

    deletelist(head);
    free(head);
    head = NULL;
    return 0;
}
