//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution3.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年11月09日
//   描    述: 公式法
//=======================================================================================

/*
 * 使用公式法达到时间和空间复杂度均为O(n)
 * 杨辉三角其实可以看做由组合数构成, 如
 * C[0](0)
 * C[1](0) C[1](1)
 * C[2](0) C[2](1) C[2](2)
 * C[3](0) C[3](1) C[3](2) C[3](3)
 * 注[]代表下标, ()代表上标
 * 而 C[m](n) = m! / (n! * (m - n)!) = (m * (m - 1) * ... * (m - n + 2) * (m - n + 1)) / (1 * 2 * ... * (n - 1) * n)
 *    C[m](n - 1) = (m * (m - 1) * ... * (m - n + 3) * (m - n + 2)) / (1 * 2 * ... * (n - 2) * (n - 1))
 * 所以得出前后两个组合数的关系, 即 C[m](n) = C[m](n - 1) * (m - n + 1) / n
 * 
 * 时间复杂度 = O(n)
 * 空间复杂度 = O(n)
 */

#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize)
{
    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));
    row[0] = 1;
    for(int i = 1; i <= rowIndex; ++i)
    {
        row[i] = ((long)row[i - 1] * (rowIndex - i + 1)) / i;
    }

    *returnSize = rowIndex + 1;
    return row;
}

int main()
{
    int returnSize = 0;
    int* row = getRow(30, &returnSize);
    for(int i = 0; i < returnSize; ++i)
    {
        printf("%d ", row[i]);
    }
    printf("\n");
    
    free(row);
    return 0;
}

