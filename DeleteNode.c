/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : DeleteNode.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/06/12 20:20:48
*  @Last Modified  : 2017/08/10 19:01:23
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} Node;

//如果要删除的节点有下结点，则直接把下个节点的data和next指针复制到当前结点，
//然后删除下个结点。这就相当于删除了当前节点。

void DeleteNode(Node **head, Node *toBeDelete)
{
    if(head == NULL || *head == NULL || toBeDelete == NULL)
        return;

    if(toBeDelete->next != NULL) //删除非尾结点
    {
        //把下个结点的数据和next指针复制到当前结点，然后删除下个结点。这相当于删除当前结点。
        Node *currNode = toBeDelete;
        Node *nextNode = toBeDelete->next;
        currNode->data = nextNode->data;
        currNode->next = nextNode->next;
        free(nextNode);
    }
    else //删除尾结点
    {
        Node **tail = head;
        while(*tail != toBeDelete)
            tail = &(*tail)->next;
        *tail = NULL;
        free(toBeDelete);
    }

    toBeDelete = NULL;
}

void deleteNode(Node **head, Node *node)
{
    if(head == NULL || *head == NULL || node == NULL)
        return;
    if(node->next != NULL)
    {
        Node *temp = node->next;
        memcpy(node, node->next, sizeof(Node));
        free(temp);
    }
    else
    {
        Node **toBeDelete = head;
        while(*toBeDelete != node)
            toBeDelete = &(*toBeDelete)->next;
        free(*toBeDelete);
        *toBeDelete = NULL;
    }
}
