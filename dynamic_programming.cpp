/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : dynamic_programming.cpp
*  @Author         : scm 351721714@qq.com
*  @Create         : 2017/07/23 11:37:35
*  @Last Modified  : 2017/10/12 13:23:16
********************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

/*
 * 动态规划法是将一个问题化解为多个子问题，当某个给定的子问题的解已经算出时，将其记
 * 忆存储，以便下次解决同一个子问题时直接给出答案，避免重复计算。动态规划适用于有重
 * 叠子问题和最优子结构性质的问题，通常能把指数级的算法复杂度下降为多项式的算法复杂度。
 */

/*
 * 01背包问题：有n件商品，每件商品的重量与价值都不同(假设第i件商品价值和重量都为i+1)。
 * 如果有一个背包，最大承重为m。问背包能装下的最大多少价值的商品。
 */
//状态转移方程(其中 j >= wight[i])：
// f(i, j) = max(f(i-1, j), f(i-1, j-wight[i]) + value[i])

#define N 5
#define M 11

int wight[N + 1] = {0, 1, 2, 3, 4, 5};
int value[M + 1] = {0, 1, 2, 3, 4, 5};
int table[N + 1][M + 1] = {{0, 0}};

//01背包问题直观写法
/*
 * int knapsack(int n, int m, int w[], int v[])
 * {
 *     for(int i = 1; i <= n; ++i)
 *     {
 *         for(int j = 1; j <= m; ++j)
 *         {
 *             if(j >= w[i])
 *                 table[i][j] = std::max(table[i-1][j], table[i-1][j-w[i]] + v[i]);
 *             else
 *                 table[i][j] = table[i-1][j]; 
 *         }
 *     }
 *     return table[n][m];
 * }
 */

//01背包问题优化空间的写法
//n个物品，背包承重为m，每件物品的重量存在数组w中，每件物品的价值存在数组v中。
int knapsack(int n, int m, int w[], int v[])
{
    int *dp = (int *)malloc(sizeof(int) * (m + 1));
    memset(dp, 0, sizeof(int) * (m + 1));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = m; j >= w[i]; --j)
            dp[j] = std::max(dp[j], dp[j-w[i]] + v[i]);
    }
    int maxValue = dp[m];
    free(dp);
    return  maxValue;
}

//完全背包问题: 每种商品的个数是无限的
//n个物品，背包承重为m，每件物品的重量存在数组w中，每件物品的价值存在数组v中。
int Completeknapsack(int n, int m, int w[], int v[])
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            table[i][j] = table[i-1][j];
            int count = j / w[i];
            for(int k = 1; k <= count; ++k)
            {
                table[i][j] = std::max(table[i][j], table[i-1][j-k*w[i]] + k*v[i]);
            }
        }
    }
    return  table[n][m];
}

/*
 * int Completeknapsack(int n, int m, int w[], int v[])
 * {
 *     int *dp = (int *)malloc(sizeof(int) * (m + 1));
 *     memset(dp, 0, sizeof(int) * m);
 *     for(int i = 1; i <= n; ++i)
 *     {
 *         for(int j = w[i]; j <= m; ++j)
 *             dp[j] = std::max(dp[j], dp[j-w[i]] + v[i]);
 *     }
 *     int maxValue = dp[m];
 *     free(dp);
 *     return  maxValue;
 * }
 */

//给出一个数组，求数组中的最长递增子数组的长度，如: [1, 5, 2, 6, -1, 7, 8]的最长
//递增子数组为[1, 5, 6, 7, 8]
int maxSubArray(int array[], int n)
{
    if(array == NULL || n < 1)
        return 0;
    int *dp = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; ++i)
        dp[i] = 1;
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(array[i] > array[j])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
    }
    int max = dp[n-1];
    free(dp);
    return max;
}

//求连续子数组的最大和
//例如：A={-3, 1, -3, 4, -1, 2, 1}，连续子数组{4, -1, 2, 1}具有最大值6。
bool g_InvalidInput = false;
int maxContinueSubArray(int a[], int n)
{
    if(a == NULL || n < 1)
    {
        return 0;
        g_InvalidInput = true;
    }
    g_InvalidInput = false;
    int currMax = a[0], max = a[0];
    for(int i = 1; i < n; ++i)
    {
        currMax = std::max(a[i], currMax + a[i]);
        max = std::max(currMax, max);
    }
    return max;
}

//求最大公共子字符串
int LongestCommonSubstring(const char *s1, const char *s2)
{
    if(s1 == NULL || s2 == NULL) return 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 == 0 || len2 == 0) return 0;
    int *dp = (int *)malloc(sizeof(int) * len1 * len2);
    memset(dp, 0, sizeof(int) * len1 * len2);
    int maxSubStrLen = 0, subStrEndIndex = 0;
    for(int i = 0; i < len1; ++i)
    {
        for(int j = 0; j < len2; ++j)
        {
            if(s1[i] == s2[j])
            {
                int *subStrLen = &dp[len1 * j + i];
                if(i > 0 && j > 0)
                    *subStrLen = dp[len1*(j-1) + (i-1)] + 1; //当前最大子串长度为前一个子串长度加1
                else
                    *subStrLen = 1;
                
                if(*subStrLen > maxSubStrLen)
                {
                    maxSubStrLen = *subStrLen;
                    subStrEndIndex = i;
                }
            }
        }
    }
    for(int i = subStrEndIndex - maxSubStrLen + 1; i <= subStrEndIndex; ++i)
        printf("%c", s1[i]);
    printf("\n");
    free(dp);
    return maxSubStrLen;
}

//求最大共公子序列
int LongestCommonSequence(const char *s1, const char *s2)
{
    if(s1 == NULL || s2 == NULL) return 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 == 0 || len2 == 0) return 0;
    int *dp = (int *)malloc(sizeof(int) * len1 * len2);
    int maxSeqLen = 0;
    for(int i = 0; i < len1; ++i)
    {
        for(int j = 0; j < len2; ++j)
        {
            int *seqLen = &dp[len1 * j + i];
            if(s1[i] == s2[j])
            {
                if(i > 0 && j > 0)
                    *seqLen = dp[len1*(j-1) + (i-1)] + 1;
                else
                    *seqLen = 1;
                
                if(*seqLen > maxSeqLen)
                    maxSeqLen = *seqLen;
            }
            else
            {
                if(i > 0 && j > 0)
                    *seqLen = std::max(dp[len1*(j-1) + i], dp[len1*j + (i-1)]);
                else
                    *seqLen = 0;
            }
        }
    }
    free(dp);
    return maxSeqLen;
}

//求最大回字符串
int palindrome(const char *str)
{
    if(str == NULL) return 0;
    int len = strlen(str);
    bool *dp = (bool *)malloc(sizeof(bool) * len * len);
    int maxLen = 1;         //最大回文子串的长度
    int maxSubStrBegin = 0; //最大回文子串的起始位置
    //每个字符都是一个回文字符串
    for(int i = 0; i < len; ++i)
        dp[len*i + i] = true;
    for(int i = 1; i < len; ++i)
    {
        for(int j = i - 1; j >= 0; --j)
        {
            //判断j~i之间的子串是否是回文字符串
            //如果j和i相邻，则不存在内部子串，只需要判断str[j]和str[i]是否相等
            bool subStrIsPlindrome = (j == i-1) ? true : dp[len * (j + 1) + (i - 1)];
            //如果str[j]等于str[i]且它们的内部子串是回文字符串，则j~i子串是回文字串
            dp[len * j + i] = (str[i] == str[j]) && subStrIsPlindrome;
            if(dp[len * j + i] == true)
            {
                if(maxLen < i - j + 1)
                {
                    maxLen = i - j + 1;
                    maxSubStrBegin = j;
                }
            }
        }
    }
    for(int i = 0; i < maxLen; ++i)
        printf("%c", str[maxSubStrBegin+i]);
    printf("\n");
    free(dp);
    return maxLen;
}

int main(int argc, char *argv[])
{
    int array[] = {1, 5, 2, 6, -1, 7, 8};
    printf("%d\n", maxSubArray(array, sizeof(array)/sizeof(array[0])));

    int array1[] = {-3, 1, -3, 4, -1, 2, 1};
    printf("%d\n", maxContinueSubArray(array1, sizeof(array1)/sizeof(array1[0])));

    char palindromeStr[] = "labcdedcbafg";
    printf("palindrome: %d\n", palindrome(palindromeStr));

    const char *s1 = "abcfggatlkm";
    const char *s2 = "dcfggaelm";
    printf("LongestCommonSubstring of \"%s\" \"%s\": %d\n", s1, s2, LongestCommonSubstring(s1, s2));

    printf("LongestCommonSequence: %d\n", LongestCommonSequence(s1, s2));
    return 0;
}
