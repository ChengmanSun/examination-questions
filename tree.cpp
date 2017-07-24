/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : tree.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/05/21 12:59:10
*  @Last Modified  : 2017/07/24 15:16:03
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <vector>
#include <stack>
#include <map>

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

void mirrorTree(TreeNode *root)
{
    if(root == NULL)
        return;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}

//------------------------------------------------------------------------------

//从上往下打印二叉树
void PrintTopToBottom(TreeNode *root)
{
    if(root == NULL)
        return;
    std::deque<TreeNode *> dq;  
    dq.push_back(root);
    while(!dq.empty())
    {
        TreeNode *node = dq.front();
        dq.pop_front();
        printf("%d ", node->data);
        if(node->left != NULL)
            dq.push_back(node->left);
        if(node->right != NULL)
            dq.push_back(node->right);
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

void findPath(TreeNode *node, std::vector<TreeNode *> &path, int currsum, int sum)
{
    if(node == NULL)
        return;
    currsum += node->data;
    path.push_back(node);
    //判断当前节点是否是叶子节点
    bool isLeaf = node->left == NULL && node->right == NULL;
    if(currsum == sum && isLeaf)
    {
        for(std::vector<TreeNode *>::iterator iter = path.begin(); iter != path.end(); ++iter)
            printf("%d ", (*iter)->data);
        printf("\n");
    }
    //如果不是叶子结节点则遍历它的子结点
    findPath(node->left, path, currsum, sum);
    findPath(node->right, path, currsum, sum);
    //返回到父结点之前，在路径上删除当前结点，并减去当前值。
    currsum -= node->data;
    path.pop_back();
}

void findTreePath(TreeNode *root, int sum)
{
    if(root == NULL)
        return;
    std::vector<TreeNode *> path;
    int currsum = 0;
    findPath(root, path, currsum, sum);
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
int treeDeepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    int left = treeDeepth(root->left);
    int right = treeDeepth(root->right);
    return left > right ? left + 1 : right + 1;
}

//------------------------------------------------------------------------------

//求树是否平衡
//法一，多次遍历同一个节点，效率差。
bool isBalance(TreeNode *root)
{
    if(root == NULL)
        return true;
    int left = treeDeepth(root->left);
    int right = treeDeepth(root->right);
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

//------------------------------------------------------------------------------

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
    inorderTraversal(root->left);
    printf("%d\n", root->data);
    inorderTraversal(root->right);
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

//------------------------------------------------------------------------------

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
    std::stack<TreeNode *> stk;
    TreeNode *p = root;
    while(p != NULL || !stk.empty())
    {
        while(p != NULL)
        {
            stk.push(p);
            p = p->left;
        }

        if(!stk.empty())
        {
            p = stk.top();
            stk.pop();
            printf("%d\n", p->data);
            p = p->right;
        }
    }
}

//后序遍历，非递归
void postorderTraversal_nonrecursive(TreeNode *root)
{
    if(root == NULL)
        return;
    std::stack<TreeNode *> stk;
    stk.push(root);
    TreeNode *prev = NULL;
    while(!stk.empty())
    {
        TreeNode *curr = stk.top();
        if((curr->left == NULL && curr->right == NULL) || (prev != NULL && (curr->left == prev || curr->right == prev)))
        {
            printf("%d\n", curr->data);
            prev = curr;
            stk.pop();
        }
        else
        {
            if(curr->right != NULL)
                stk.push(curr->right);
            if(curr->left != NULL)
                stk.push(curr->left);
        }
    }
}

//------------------------------------------------------------------------------

//给定二叉搜索树的两个节点，求这两个节点的最小公共祖先。
//解析：这两个节点的最小公共祖先的值，大于这两个节点中的较小值，小于较大值。
TreeNode *leastforefather(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == NULL || p == NULL || q == NULL) return NULL;
    if(root->data < p->data && root->data < q->data)
        leastforefather(root->right, p, q);
    else if(root->data > p->data && root->data > q->data)
        leastforefather(root->left, p, q);
    else
        return root;
}

//给定二叉树的两个节点，求两个节点的最小公共祖先。每个节点除了有左右子节点外还有
//一个指向父节点的指针。
typedef struct TreeNode_ {
    int data;
    struct TreeNode_ *parent;
    struct TreeNode_ *left;
    struct TreeNode_ *right;
} TreeNode_;
TreeNode_ *leastforefather_1(TreeNode_ *root, TreeNode_ *p, TreeNode_ *q)
{
    if(root == NULL || p == NULL || q == NULL) return NULL;
    int plen = 0, qlen = 0;
    for(TreeNode_ *temp = p; temp != root; temp = temp->parent)
        ++plen;
    for(TreeNode_ *temp = q; temp != root; temp = temp->parent)
        ++qlen;
    while(plen > qlen)
    {
        p = p->parent;
        --plen;
    }
    while(qlen > plen)
    {
        q = q->parent;
        --qlen;
    }
    while(p != q)
    {
        p = p->parent;
        q = q->parent;
    }
    return p;
}

//------------------------------------------------------------------------------

//给定一棵普通二叉树的两个节点，求它们的最小公共祖先。
void nodeMapParent(TreeNode *root, std::map<TreeNode*, TreeNode *> &mp)
{
    if(root == NULL) return;
    mp[root->left] = root;
    mp[root->right] = root;
    nodeMapParent(root->left, mp);
    nodeMapParent(root->right, mp);
}

TreeNode *findforefather(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == NULL) return NULL;
    std::map<TreeNode *, TreeNode *> mp;
    nodeMapParent(root, mp);
    int plen = 0, qlen = 0;
    for(TreeNode *temp = p; mp.find(temp) != mp.end(); temp = mp.find(temp)->second)
        ++plen;
    for(TreeNode *temp = q; mp.find(temp) != mp.end(); temp = mp.find(temp)->second)
        ++qlen;

    while(plen > qlen)
    {
        p = mp.find(p)->second;
        --plen;
    }
    while(plen < qlen)
    {
        q = mp.find(q)->second;
        --qlen;
    }
    while(p != q)
    {
        p = mp.find(p)->second;
        q = mp.find(q)->second;
    }
    return p;
}

//------------------------------------------------------------------------------

//给出二叉树的前序遍历和中序遍历，请重建二叉树
int g_InvalidInput = 0;
TreeNode *constructCore(int *preorderStart, int *preorderEnd, int *inorderStart, int *inorderEnd)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode)); 
    node->data = *preorderStart;
    node->left = node->right = NULL;

    if(preorderStart == preorderEnd)
    {
        if(inorderStart == inorderEnd && *preorderStart == *inorderStart)
            return node;
        else
        {
            free(node);
            g_InvalidInput = 1;
            return NULL;
        }
    }

    int *inorderRoot = inorderStart;
    while(inorderRoot <= inorderEnd && *inorderRoot != *preorderStart)
        ++inorderRoot;
    if(inorderRoot > inorderEnd)
    {
        free(node);
        g_InvalidInput = 1;
        return NULL;
    }

    int leftLen = inorderRoot - inorderStart;
    int rightLen = inorderEnd - inorderRoot;
    if(leftLen > 0)
        node->left = constructCore(preorderStart + 1, preorderStart + leftLen,
                                    inorderStart, inorderRoot - 1);
    if(rightLen > 0)
        node->right = constructCore(preorderEnd - rightLen + 1, preorderEnd,
                                    inorderRoot + 1, inorderEnd);

    return node;
}
void distroyTree(TreeNode *root)
{
    if(root == NULL)
        return;
    distroyTree(root->left);
    distroyTree(root->right);
    free(root);
}
TreeNode *constructTree(int preorder[], int inorder[], int len)
{
    if(preorder == NULL || inorder == NULL || len <= 0)
    {
        g_InvalidInput = 1;
        return NULL;
    }
    g_InvalidInput = 0;
    TreeNode *root = constructCore(preorder, preorder + len - 1,
                            inorder, inorder + len - 1); 
    if(g_InvalidInput)
    {
        distroyTree(root);
        root = NULL;
    }
    return root;
}
//------------------------------------------------------------------------------

int main(int argc, const char *argv[])
{
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[]  = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *root = constructTree(preorder, inorder, sizeof(preorder)/sizeof(preorder[0]));
    // preorderTraversal(root);
    // inorderTraversal(root);
    // postorderTraversal(root);
    // preorderTraversal_nonrecursive(root);
    // inorderTravasal_nonrecursive(root);
    // postorderTraversal_nonrecursive(root);
    // findTreePath(root, 18);
    // mirrorTree(root);
    // PrintTopToBottom(root);
    int deepth = treeDeepth(root);
    printf("deepth:%d\n", deepth);

    TreeNode *p = root->right;
    TreeNode *q = p->right;
    p = p->left;
    TreeNode *forefather = findforefather(root, p, q);
    printf("%d\n", forefather->data);
    return 0;
}
