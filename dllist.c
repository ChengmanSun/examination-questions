/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : dllist.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/29 21:30:08
*  @Last Modified  : 2017/05/29 23:09:18
********************************************************************************
*/

#include <stdio.h>
#include <malloc.h>

typedef struct double_link_node
{
    int data;
    struct double_link_node *prev;
    struct double_link_node *next;
} DLList;

void appendTail(DLList **head, int data)
{
    DLList *p = *head;
    if(head == NULL)
        return;
    DLList *node = (DLList *)malloc(sizeof(DLList));
    node->data = data;
    node->next = NULL;
    if(p == NULL)
    {
        node->prev = NULL;
        *head = node;
    }
    else
    {
        while(p->next != NULL)
            p = p->next;
        node->prev = p;
        p->next = node;
    }
}

int delete_index(DLList **head, int index)
{
    DLList *p = *head;
    if(head == NULL || p == NULL || index < 0)
        return 0;
    while(index--)
    {
        if(p == NULL)
            return 0;
        p = p->next;
    }

    if(p == *head)
    {
        *head = p->next;
        p->prev = NULL;
    }
    else
    {
        if(p->prev != NULL)
            p->prev->next = p->next;
        if(p->next != NULL)
            p->next->prev = p->prev;
    }
    free(p);
}

void traversal(DLList *head, void (*fun)(DLList *, void *), void *param)
{
    DLList *p = head;
    while(p != NULL)
    {
        fun(p, param);
        p = p->next;
    }
}

void show(DLList *node, void *param)
{
    printf("%d ", node->data);
}

int main(int argc, char *argv[])
{
    DLList *head;
    for(int i = 0; i < 10; ++i)
        appendTail(&head, i);
    traversal(head, show, 0);
    printf("\n");
    delete_index(&head, 0);
    /* delete_index(&head, 2); */
    traversal(head, show, 0);

    return 0;
}
