//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution2.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年11月09日
//   描    述: 动态规划
//=======================================================================================

/*
 * 上一题解的优化版本
 * 上一题解使用的空间复杂度是2n, 能不能把空间复杂度控制在n呢?
 * 由于原地进行计算当前值需要前一个值与当前值相加得出, 那么从后往前计算
 * 就可以把空间控制在原地进行
 * 
 * 时间复杂度 = O(n^2)
 * 空间复杂度 = O(n)
 */

#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize)
{
    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));
    row[0] = 1;
    for(int i = 0; i <= rowIndex; ++i)
    {
        row[i] = 1;
        for(int j = i - 1; j > 0; --j)
        {
            row[j] += row[j - 1];
        }
    }
    
    *returnSize = rowIndex + 1;
    return row;
}

int main()
{
    int returnSize = 0;
    int* row = getRow(3, &returnSize);
    for(int i = 0; i < returnSize; ++i)
    {
        printf("%d ", row[i]);
    }
    printf("\n");
    
    free(row);
    return 0;
}

