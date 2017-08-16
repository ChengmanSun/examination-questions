/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : constructTree.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/07/09 09:18:04
*  @Last Modified  : 2017/07/24 10:10:17
********************************************************************************
*/

//有两个数组分别是二叉树的前序遍历，另一个是中序遍历，根据这两个数组重构出二叉树。

#include <stdio.h>
#include <malloc.h>

typedef struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} Node;

int g_InvalidInput = 0;

Node *constructCore(int *preorderStart, int *preorderEnd, int *inorderStart, int *inorderEnd)
{
    Node *node = (Node *)malloc(sizeof(Node)); 
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

void distroyTree(Node *root)
{
    if(root == NULL)
        return;
    distroyTree(root->left);
    distroyTree(root->right);
    free(root);
}

Node *constructTree(int preorder[], int inorder[], int len)
{
    if(preorder == NULL || inorder == NULL || len <= 0)
        return NULL;
    g_InvalidInput = 0;
    Node *root = constructCore(preorder, preorder + len - 1,
                            inorder, inorder + len - 1); 
    if(g_InvalidInput)
    {
        distroyTree(root);
        root = NULL;
    }
    return root;
}

void treePreorderTravesal(Node *root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    treePreorderTravesal(root->left);
    treePreorderTravesal(root->right);
}

int main(int argc, char *argv[])
{
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    Node *root = constructTree(preorder, inorder, sizeof(preorder)/sizeof(preorder[0]));
    treePreorderTravesal(root);
    return 0;
}
