/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : tree.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/21 12:59:10
*  @Last Modified  : 2017/07/21 14:34:34
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <vector>
#include <stack>

typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} TreeNode;

//前序遍历：先访问根节点，然后如果有左节点不断深入左节点访问，直到左节点为NULL，
//然后返回上层节点访问右节点。前序遍历一个特点是第一个访问的节点是根节点！
//中序遍历：先访问整棵树的最左边的节点，再返回上层节点访问，再访问右节点。中序
//遍历的特点是：对于搜索二叉树，中序遍历总是从小到大访问节点。
//后序遍历：从最左边的最小子树开始，先访问最小子树的左节点再访问右节点，然后访问
//最小子树的根节点，然后访问同层次的其它最小子树。后序遍历的特点是最后访问的是整
//棵树的根节点。

//------------------------------------------------------------------------------

bool isTree1HasTree2(TreeNode *root1, TreeNode *root2)
{
    if(root2 == NULL)
        return true;
    if(root1 == NULL)
        return false;
    if(root1->data != root2->data)
        return false;
    return isTree1HasTree2(root1->left, root2->left) && isTree1HasTree2(root1->right, root2->right);
}

//前序遍历树1，对树1的每个节点查看是否有子树2。
bool HasSubTree(TreeNode *root1, TreeNode *root2)
{
    if(root1 == NULL || root2 == NULL)
        return false;
    bool result = isTree1HasTree2(root1, root2);
    if(!result)
        result = HasSubTree(root1->left, root2);
    if(!result)
        result = HasSubTree(root1->right, root2);
    return result;
}

//------------------------------------------------------------------------------

void MirrorTree(TreeNode *root)
{
    if(root == NULL)
        return;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    MirrorTree(root->left);
    MirrorTree(root->right);
}

//------------------------------------------------------------------------------

//从上往下打印二叉树
void PrintTreeFromTopToBottom(TreeNode *root)
{
    if(root == NULL)
        return;
    std::deque<TreeNode *> dq;  
    dq.push_back(root);
    while(!dq.empty())
    {
        TreeNode *front = dq.front();
        dq.pop_front();
        printf("%d ", front->data);
        dq.push_back(front->left);
        dq.push_back(front->right);
    }
}

//------------------------------------------------------------------------------

//输入一个整数数组，判断它是不是某二叉搜索树的后序遍历的结果。如果是则返回true，
//如果不是则返回false，设输入的数组的任意两个数字都不相同。

//解析：后序遍历的最后一个数字是树的根节点。而二叉搜索树的任意节点值大于等于它的
//左子节点，小于等于右子节点。

//verify:证明、判定

bool VerifySequenceOfBST(int sequence[], int length)
{
    if(sequence == NULL || length <= 0)
        return false;
    int root = sequence[length-1];
    //在二叉搜索树中左子树的结点小于根节点
    int i = 0;
    for(; i < length - 1; ++i)
    {
        if(sequence[i] > root)
            break;
    }
    //在二叉搜索树中右子树的结点大于根节点
    int j = i;
    for(; j < length - 1; ++j)
    {
        if(sequence[j] < root)
            return false;
    }

    bool left = true;
    if(i > 0)
        left = VerifySequenceOfBST(sequence, i);
    bool right = true;
    if(j < length - 1)
        right = VerifySequenceOfBST(sequence + i, length - i - 1);
    return left && right;
}

//------------------------------------------------------------------------------

//输入一棵二叉树和一个整数，打印出二叉树中结点的值为输入整数的所有路径。从树的根
//结点往下一直到叶子结点所经过的结点形成一条路径。

void FindPath(TreeNode *node, std::vector<TreeNode *> &path, int value, int &sum)
{
    if(node == NULL)
        return;
    sum += node->data;
    path.push_back(node);
    //判断当前节点是否是叶子节点
    bool isLeaf = node->left == NULL && node->right == NULL;
    if(sum == value && isLeaf)
    {
        for(std::vector<TreeNode *>::iterator iter = path.begin(); iter != path.end(); ++iter)
            printf("%d ", (*iter)->data);
        printf("\n");
    }
    //如果不是叶子结节点则遍历它的子结点
    FindPath(node->left, path, value, sum);
    FindPath(node->right, path, value, sum);
    //返回到父结点之前，在路径上删除当前结点，并减去当前值。
    sum -= node->data;
    path.pop_back();
}

void FindTreePath(TreeNode *root, int sum)
{
    if(root == NULL)
        return;
    std::vector<TreeNode *> path;
    int value = 0;
    FindPath(root, path, value, sum);
}

//------------------------------------------------------------------------------

//把一棵搜索二叉树转换成一个双向排抒链表。要求不能创建任何新节点，只能调整树的节点指针。

void Convert(TreeNode *node, TreeNode **listTail)
{
    if(node == NULL)
        return;
    Convert(node->left, listTail);
    node->left = *listTail;
    if(*listTail != NULL)
        (*listTail)->right = node;
    *listTail = node;
    Convert(node->right, listTail);
}

TreeNode *TreeConvertToDoubleList(TreeNode *root)
{
    TreeNode *listTail = NULL;
    Convert(root, &listTail);
    TreeNode *listHead = listTail;
    if(listHead != NULL)
        while(listHead->left != NULL)
            listHead = listHead->left;
    return listHead;
}

//------------------------------------------------------------------------------

//求树的深度
int TreeDeepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    int left = TreeDeepth(root->left);
    int right = TreeDeepth(root->right);
    return left > right ? left + 1 : right + 1;
}

//------------------------------------------------------------------------------

//求树是否平衡
//法一，多次遍历丗一个节点，效率差。
bool isBalance(TreeNode *root)
{
    if(root == NULL)
        return true;
    int left = TreeDeepth(root->left);
    int right = TreeDeepth(root->right);
    if(abs(left - right) > 1)
        return false;
    return isBalance(root->left) && isBalance(root->right);
}

//法二，不需要多次遍历同一个节点，效率高。
bool isBalance(TreeNode *root, int *deepth)
{
    if(root == NULL)
    {
        *deepth = 0;
        return true;
    }
    int leftDeepth, rightDeepth;
    if(isBalance(root->left, &leftDeepth) && isBalance(root->right, &rightDeepth))
    {
        if(abs(leftDeepth - rightDeepth) <= 1)
        {
            *deepth = leftDeepth > rightDeepth ? leftDeepth + 1 : rightDeepth + 1;
            return true;
        }
        else
            return false;
    }
    return false;
}

//前序遍历，递归
void preorderTraversal(TreeNode *root)
{
    if(root == NULL)
        return;
    printf("%d\n", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//中序遍历，递归
void inorderTraversal(TreeNode *root)
{
    if(root == NULL)
        return;
    preorderTraversal(root->left);
    printf("%d\n", root->data);
    preorderTraversal(root->right);
}

//后序遍历，递归
void postorderTraversal(TreeNode *root)
{
    if(root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\n", root->data);
}

//前序遍历，非递归
void preorderTraversal_nonrecursive(TreeNode *root)
{
    if(root == NULL)
        return;
    std::stack<TreeNode *> stk;
    stk.push(root);
    while(!stk.empty())
    {
        TreeNode *temp = stk.top();
        stk.pop();
        printf("%d\n", temp->data);
        if(temp->right != NULL)
            stk.push(temp->right);
        if(temp->left != NULL)
            stk.push(temp->left);
    }
}

//中序遍历，非递归
void inorderTravasal_nonrecursive(TreeNode *root)
{
    if(root == NULL)
        return;
    std::stack<TreeNode *> stk;
    stk.push(root);
    while(!stk.empty())
    {
        while(stk.top()->left != NULL)
            stk.push(stk.top()->left);
        TreeNode *temp = stk.top();
        stk.pop();
        printf("%d\n", temp->data);
        if(temp->right != NULL)
            stk.push(temp->right);
    }
}

//后序遍历，非递归
void postorderTraversal_nonrecursive(TreeNode *root)
{
    if(root == NULL)
        return;
    std::stack<TreeNode *> stk;
    stk.push(root);
    TreeNode *preVisit = NULL;
    while(!stk.empty())
    {
        TreeNode *top = stk.top();
        for(; top->left != preVisit && top->right != preVisit; top = stk.top())
        {
            if(top->right != NULL)
                stk.push(top->right);
            if(top->left != NULL)
                stk.push(top->left);
        }
        printf("%d\n", top->data);
        preVisit = top;
        stk.pop();
    }
}
