//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年11月08日
//   描    述: 动态规划
//=======================================================================================

/*
 * 与118题相类似, 可以采用类似动态规划的方法, 但不需要把每一层的结果都保存起来,
 * 只需保存上一层的结果, 就可以求出当前层的结果
 * 申请两个空间row和tmp, 循环[0, rowIndex], 每一次循环都交换row和tmp的指针, 以
 * 确保最后返回的是row指针
 * 
 * 时间复杂度 = O(n^2)
 * 空间复杂度 = O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#define SWAP(p1, p2) { int* __temp__ = (p1); (p1) = (p2); (p2) = __temp__; }

int* getRow(int rowIndex, int* returnSize)
{
    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));
    int* tmp = (int*)malloc((rowIndex + 1) * sizeof(int));
    for(int i = 0; i <= rowIndex; ++i)
    {
        SWAP(row, tmp);
        row[0] = 1;
        row[i] = 1;
        for(int j = 1; j < i; ++j)
        {
            row[j] = tmp[j - 1] + tmp[j];
        }
    }
    
    free(tmp);
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

