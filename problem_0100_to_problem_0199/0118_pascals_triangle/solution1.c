//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年11月08日
//   描    述: 动态规划
//=======================================================================================

/*
 * 非常简单的算法实现, 根据上一行来构造每一行
 * 首先, 我们先生成整个 triangle 列表, 每一行的第一个元素和最后一个元素存入 1,
 * 中间的第 n 个元素由上一行的第 n - 1 和第 n 个元素相加而得
 * 
 * 时间复杂度 = O(n^2)
 * 空间复杂度 = O(n^2)
 */

#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    int* sizes = (int*)malloc(numRows * sizeof(int));
    
    for(int i = 0; i < numRows; ++i)
    {
        sizes[i] = i + 1;
        triangle[i] = (int*)malloc(sizes[i] * sizeof(int));

        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for(int j = 1; j < i; ++j)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
    *returnSize = numRows;
    *returnColumnSizes = sizes;
    return triangle;
}

int main()
{
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int** triangle = generate(5, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; ++i)
    {
        for(int j = 0; j < returnColumnSizes[i]; ++j)
        {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes);

    return 0;
}

