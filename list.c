/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : list.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/15 13:58:12
*  @Last Modified  : 2017/09/05 20:59:17
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

/*
********************************************************************************
* Note : 反转链表方法一 
********************************************************************************
*/
ListNode *ListReverse1(ListNode *head)
{
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
ListNode *ListReverse2(ListNode *head)
{
    ListNode *reverseList = NULL;
    while(head != NULL)
    {
        ListNode *temp = head;
        head = head->next;
        temp->next = reverseList;
        reverseList = temp;
    }
    return reverseList;
}

/*
********************************************************************************
* Note : 反转链表方法三 
********************************************************************************
*/
ListNode *ListReverse3(ListNode *head, ListNode **newlist)
{
    if(head == NULL || newlist == NULL) return NULL;
    ListNode *prevNote = ListReverse3(head->next, newlist);
    if(prevNote == NULL)
        *newlist = head;
    else
        prevNote->next = head;
    head->next = NULL; //必须将head->next设置成NULL，否则最后会死循环
    return head;
}

//合并两个升序链表 方法一
ListNode *ListMerge1(ListNode *node1, ListNode *node2)
{
    if(node1 == node2) return node1;
    if(node1 == NULL) return node2;
    if(node2 == NULL) return node1;
    ListNode *less = NULL;
    if(node1->data < node2->data)
    {
        less = node1;
        less->next = ListMerge1(node1->next, node2);
    }
    else
    {
        less = node2;
        less->next = ListMerge1(node1, node2->next);
    }
    return less;
}

//合并两个升序链表 方法二
ListNode *ListMerge2(ListNode *list1, ListNode *list2)
{
    if(list1 == list2) return list1;
    ListNode *newList = NULL, **tail = &newList;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->data < list2->data)
        {
            *tail = list1;
            list1 = list1->next;
        }
        else
        {
            *tail = list2;
            list2 = list2->next;
        }
        tail = &((*tail)->next);
    }
    if(list1 != NULL) *tail = list1;
    if(list2 != NULL) *tail = list2;
    return newList;
}

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
int ListHasCycle(ListNode *head)
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
int cycleLength(ListNode *head)
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

    //如果无环，则返回无环链表的长度
    if(fast == NULL) return 2*len;
    if(fast->next == NULL) return 2*len + 1;

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

/*
********************************************************************************
* Note : 使用并归法排序链表 
********************************************************************************
*/
ListNode *splitMiddle(ListNode *head)
{
    if(head == NULL) return NULL;
    ListNode *fast = head, *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        //当链表只有两个节点时，最终slow应该指向第一个节点。
        //这样就能将只有两个节点的链表拆分成两个分别有一个节点的链表。
        if(fast != NULL)
            slow = slow->next;
    }
    ListNode *newlist = slow->next; 
    slow->next = NULL;
    return newlist;
}

ListNode *mergeSort(ListNode *head)
{
    if(head == NULL) return NULL;
    //必须，否则如果一个链表只有一个节点时，总是能拆分成一个NULL，和只有一个节点的链表，结果就会死循环无限拆分
    if(head->next == NULL) return head;

    ListNode *list1 = head;
    ListNode *list2 = splitMiddle(head);
    list1 = mergeSort(list1);
    list2 = mergeSort(list2);
    ListNode *newlist = NULL, **tail = &newlist;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->data < list2->data)
        {
            *tail = list1;
            list1 = list1->next;
        }
        else
        {
            *tail = list2;
            list2 = list2->next;
        }
        tail = &((*tail)->next);
    }
    if(list1 != NULL) *tail = list1;
    if(list2 != NULL) *tail = list2;
    return newlist;
}

int main(int argc, char *argv[])
{
    ListNode *list = NULL, *list1 = NULL, *list2 = NULL;
    int data[] = {1, 9, 3, 7, 2, 4, 10, 6, 8, 5};
    int data1[] = {1, 3, 4, 9, 10};
    int data2[] = {0, 5, 2, 8, 7, 6};
    for(unsigned i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        ListAddToTail(&list, data[i]);
        if(i < sizeof(data1)/sizeof(int))
            ListAddToFront(&list1, data1[i]);
        if(i < sizeof(data2)/sizeof(int))
            ListAddToFront(&list2, data2[i]);
    }

    list = mergeSort(list);
    list1 = mergeSort(list1);
    list2 = mergeSort(list2);
    ListShow(list);
    ListShow(list1);
    ListShow(list2);

    list = ListReverse1(list);
    /* list = ListReverse2(list); */
    /* ListNode *reverse; */
    /* ListReverse3(list, &reverse); */
    ListShow(list);
    ListRemoveNode(&list, 1);
    ListRemoveNode(&list, 5);
    ListShow(list);

    ListNode *middle = ListFindMiddle(list);
    printf("middle of list: %d\n", middle->data);

    /* ListNode *mergeList = ListMerge1(list1, list2); */
    ListNode *mergeList = ListMerge2(list1, list2);
    printf("merge list1 list2: ");
    ListShow(mergeList);

    return 0;
}
