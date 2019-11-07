//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution3.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年11月06日
//   描    述: 分治法
//=======================================================================================

/*
 * 首先根据题目确定两个概念
 * 左连通值: 序列连通其左边界的最大值, 如[-2, 1, -5, 4], 其左连通值是 -2 + 1 = -1
 * 右连通值: 序列连通其右边界的最大值, 如[-2, 1, -5, 4], 其右连通值是 4
 * 
 * 根据分治法的思想, 一个序列的最大子序列, 要么是左子序列的最大子序列, 要么是右子序列的最大子序列,
 * 要么是其左子序列的右连通值加上其右子序列的左连通值
 * 
 * 接下来需要思考如何求出左右连通值
 * 一个序列的左连通值, 要么是其左子序列的左连通值, 要么是其左子序列的总和加上其右子序列的左连通值,
 * 如[4, -2, 1, -3], 其左子序列的左连通值是4, 左子序列的总和是2, 右子序列的左连通值是1,
 * 故其左连通是 4 和 2 + 1 的最大值, 即 4
 * 右连通值也是同理可得出
 * 
 * 所以, 对于一个序列, 我们需要存入其四个值, 即左连通值, 右连通值, 最大子序列和, 总和
 * 
 * 时间复杂度 = O(n)
 * 空间复杂度 = O(logn)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX(var1, var2) ((var1) > (var2) ? (var1) : (var2))
#define MEMORY_INIT(size) { memory_pool = (int*)malloc((size)); memory_stack = (int*)malloc((size) >> 2); }
#define MEMORY_DEL() { free(memory_pool); free(memory_stack); memory_pool = NULL; memory_stack = NULL; memory_top = -1; memory_index = 0; }
#define MEMORY_PUSH(target) { ++memory_top; memory_stack[memory_top] = (target) - memory_pool; }
#define MEMORY_POP() { --memory_top; }
#define DEALLOCATE(target) { MEMORY_PUSH((target)); }
#define ALLOCATE(target)\
{\
    if(-1 == memory_top)\
    {\
        (target) = memory_pool + memory_index;\
        memory_index += 4;\
    }\
    else\
    {\
        (target) = memory_pool + memory_stack[memory_top];\
        MEMORY_POP();\
    }\
}

int *memory_pool = NULL;
int *memory_stack = NULL;
int memory_top = -1;
int memory_index = 0;

int* mergeCount(int* nums, int begin, int end)
{
    int *ret = NULL;
    ALLOCATE(ret);

    if(begin < end)
    {
        int middle = (begin + end) >> 1;
        int *left = mergeCount(nums, begin, middle);
        int *right = mergeCount(nums, middle + 1, end);

        // 左连通值, 右连通值, 最大子序列和, 总和
        ret[0] = MAX(left[0], left[3] + right[0]);
        ret[1] = MAX(right[1], right[3] + left[1]);
        ret[2] = MAX(MAX(left[2], right[2]), left[1] + right[0]);
        ret[3] = left[3] + right[3];
        
        DEALLOCATE(left);
        DEALLOCATE(right);
        return ret;
    }

    for(int i = 0; i < 4; ++i)
    {
        ret[i] = nums[begin];
    }

    return ret;
}

int maxSubArray(int* nums, int nums_size)
{
    MEMORY_INIT(((int)(log((double)nums_size)/log(2.0)) + 1) << 5);
    
    int *result = mergeCount(nums, 0, nums_size - 1);
    int ret = result[2];
    
    MEMORY_DEL();
    result = NULL;

    return ret;
}

int main()
{
    int nums[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    printf("%d\n", maxSubArray(nums, 9));
    
    return 0;
}

