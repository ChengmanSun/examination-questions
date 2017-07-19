/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : list.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/15 13:58:12
*  @Last Modified  : 2017/07/19 10:29:14
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
} ListNode;

void ListAddToTail(ListNode **head, int value)
{
    ListNode **tail, *node;
    if(head == NULL)
        return;

    node = (ListNode *)malloc(sizeof(ListNode));
    node->data = value;
    node->next = NULL;

    tail = head;
    while(*tail != NULL)
        tail = &(*tail)->next;
    *tail = node;
}

void ListAddToFront(ListNode **head, int value)
{
    ListNode *node;
    if(head == NULL)
        return;
    node = (ListNode *)malloc(sizeof(ListNode));
    node->data = value;
    node->next = *head;
    *head = node;
}

void ListRemoveNode(ListNode **head, int value)
{
    ListNode **node = head, *ToBeDelete = NULL;
    if(head == NULL)
        return;
    while(*node != NULL)
    {
        if(value == (*node)->data)
        {
            ToBeDelete = *node;
            *node = (*node)->next;
            free(ToBeDelete);
            break;
        }
        node = &((*node)->next);
    }
}

void ListSort(ListNode *head)
{
    ListNode *p = head, *q;
    if(head == NULL)
        return;
    while(p->next != NULL)
    {
        q = p->next;
        while(q != NULL)
        {
            if(p->data > q->data)
            {
                p->data ^= q->data;
                q->data ^= p->data;
                p->data ^= q->data;
            }
            q = q->next;
        }
        p = p->next;
    }
}

/*
********************************************************************************
* Note : 反转链表方法一 
********************************************************************************
*/
ListNode *ListReverse(ListNode *head)
{
    if(head == NULL)
        return NULL;
    ListNode *prev = NULL, *curr = head;
    while(curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/*
********************************************************************************
* Note : 反转链表方法二 
********************************************************************************
*/
/*
 * ListNode *ListReverse(ListNode *head)
 * {
 *     ListNode *reverseList = NULL;
 *     while(head != NULL)
 *     {
 *         ListNode *temp = head;
 *         head = head->next;
 *         temp->next = reverseList;
 *         reverseList = temp;
 *     }
 *     return reverseList;
 * }
 */

/*
********************************************************************************
* Note : 反转链表方法三 
********************************************************************************
*/
ListNode *ListReverse(ListNode *head, ListNode **reverselist)
{
    ListNode *note;
    if(head == NULL || reverselist == NULL)
        return NULL;
    note = ListReverse(head->next, reverselist);
    if(note != NULL)
        note->next = head;
    else
        *reverselist = head;
    head->next = NULL;
    return head;
}

//合并两个升序链表 方法一
ListNode *ListMerge(ListNode *node1, ListNode *node2)
{
    if(node1 == node2)
        return node1;
    if(node1 == NULL)
        return node2;
    if(node2 == NULL)
        return node1;
    ListNode *less = NULL;
    if(node1->data < node2->data)
    {
        less = node1;
        less->next = ListMerge(node1->next, node2);
    }
    else
    {
        less = node2;
        less->next = ListMerge(node1, node2->next);
    }
    return less;
}

//合并两个升序链表 方法二
ListNode *merge(ListNode *node1, ListNode *node2)
{
    if(node1 == NULL || node2 == NULL)
        return NULL;
    if(node1 == node2)
        return node1;
    ListNode *mergeList = NULL;
    ListNode **tail = &mergeList;
    while(node1 != NULL && node2 != NULL)
    {
        if(node1->data < node2->data)
        {
            *tail = node1;
            node1 = node1->next;
        }
        else
        {
            *tail = node2;
            node2 = node2->next;
        }
        tail = &(*tail)->next;
    }
    if(node1 != NULL)
        *tail = node1;
    if(node2 != NULL)
        *tail = node2;
    return mergeList;
}

//合并两个降序链表
/*
 * ListNode *ListMerge(ListNode *h1, ListNode *h2)
 * {
 *     ListNode *list = NULL;
 *     if(h1 == NULL)
 *         return h2;
 *     if(h2 == NULL)
 *         return h1;
 *     if(h1->data > h2->data)
 *     {
 *         list = h1;
 *         list->next = ListMerge(h1->next, h2); 
 *     }
 *     else
 *     {
 *         list = h2;
 *         list->next = ListMerge(h1, h2->next);
 *     }
 *     return list;
 * }
 */

void ListShow(ListNode *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void ListReversePrint(ListNode *head)
{
    if(head == NULL)
        return;
    ListReversePrint(head->next);
    printf("%d ", head->data);
}

/*
********************************************************************************
* Note : 只遍历一次链表，找出中间节点。
*        分析：用两个指针*p和*q，p每次走两个节点，同时q走一个节点。当p到达终点时
*        q为链表的中间节点。 
********************************************************************************
*/
ListNode *ListFindMiddle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/*
********************************************************************************
* Note : 判断一个链表是否有环 
*        快指针每次走两步，慢指针每次走一步，如果快指针遇到NULL则链表无环。如果
*        快指针遇到慢指针则链表有环。
********************************************************************************
*/
int ListHasCircle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return 1;
    }
    return 0;
}

/*
********************************************************************************
* Note : 判断一个有环链表的环的长度
*        从相遇点开始慢指针不动，快指针再走一圈，再次相遇时快指针走过的距离为环的长度。
********************************************************************************
*/
int circlyLength(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }
    //如果链表无环，则返回0
    if(fast == NULL || fast->next == NULL)
        return 0;
    int length = 1;
    //从相遇点开始，慢指针不动，快指针走一圈，直到碰到慢指针。
    for(; fast->next != slow; fast = fast->next)
        ++length;
    return length;
}

/*
********************************************************************************
* Note : 寻找有环链表的环的入口点
*        高指针A从快慢指针的碰撞点处一次走一个节点，与此同时指针B从链表头处开始，
*        一次走一个节点，则A、B指针会在链表环入口处相遇。此时指针A可能走了几个圈，
*        也可能没走完一个圈。
********************************************************************************
*/
ListNode *findLoopPort(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }

    if(fast == NULL || fast->next == NULL)
        return NULL;

    while(head != slow)
    {
        head = head->next;
        slow = slow->next;
    }
    return head;
}

/*
********************************************************************************
* Note : 求一个带环链表的全长 
********************************************************************************
*/
int loopListLength(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    int len = 0;
    while(fast != NULL && fast->next != NULL)
    {
        ++len;
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }

    //返回无环链表的长度
    if(fast == NULL || fast->next == NULL)
        return len;

    //求环的长度：从相遇点开始，慢指针不动，快指针走一圈，直到碰到慢指针。
    len = 1;
    for(; fast->next != slow; fast = fast->next)
        ++len;

    //加上链表头到环入口的长度
    while(head != slow)
    {
        ++len;
        head = head->next;
        slow = slow->next;
    }
    return len;
}

/*
********************************************************************************
* Note : 输入两个链表，找出它们的第一个公共结点。
********************************************************************************
*/
int listLength(ListNode *head)
{
    int length = 0;
    for(ListNode *node = head; node != NULL; node = node->next)
        ++length;
    return length;
}

ListNode *findFistCommonNode(ListNode *head1, ListNode *head2)
{
    if(head1 == NULL || head2 == NULL)
        return NULL;
    int len1 = listLength(head1);
    int len2 = listLength(head2);
    int forward = abs(len1 - len2);
    ListNode *longList = head1, *shortList = head2;
    if(len1 < len2)
    {
        longList = head2;
        shortList = head1;
    }

    while(forward--)
        longList = longList->next;

    while(longList != NULL && shortList != NULL && longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }

    return longList;
}

int main(int argc, const char *argv[])
{
    ListNode *head = NULL, *head1 = NULL, *head2 = NULL, *newlist = NULL;
    int data[] = {1, 9, 3, 7, 2, 4, 10, 6, 8, 5};
    int data1[] = {1, 3, 4, 9, 10};
    int data2[] = {0, 5, 2, 8, 7, 6};
    for(unsigned i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        ListAddToTail(&head, data[i]);
        if(i < sizeof(data1)/sizeof(int))
            ListAddToFront(&head1, data1[i]);
        if(i < sizeof(data2)/sizeof(int))
            ListAddToFront(&head2, data2[i]);
    }

    ListSort(head);
    ListSort(head1);
    ListSort(head2);

    ListShow(head);
    ListShow(head1);
    ListShow(head2);

    head = ListReverse(head);
    /* ListReverse(head, &reverselist); */
    /* Show(reverselist); */
    ListRemoveNode(&head, 1);
    ListRemoveNode(&head, 5);
    ListShow(head);

    ListNode *middle = ListFindMiddle(head);
    printf("middle of head: %d\n", middle->data);

    newlist = ListMerge(head1, head2);
    printf("merge head1 head2: ");
    ListShow(newlist);

    return 0;
}
