/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : findKthOfTail.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/13 12:14:56
*  @Last Modified  : 2017/07/10 11:15:52
********************************************************************************
*/

#include <stdio.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node;

Node *findKthOfTail(Node *head, int k)
{
    if(head == NULL || k < 0)
        return NULL;

    Node *ahead = head, *behind = head;
    for(int i = 0; i < k; ++i)
    {
        if(ahead != NULL)
            ahead = ahead->next;
        else
            return NULL;
    }
    while(ahead->next != NULL)
    {
        ahead = ahead->next;
        behind = behind->next;
    }
    return behind;
}
