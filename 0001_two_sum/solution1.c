//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称：solution1.c
//   创 建 者：Junki Chu <jk.chu@foxmail.com>
//   创建日期：2019年08月24日
//   描    述：暴力法，遍历每个元素 x，查找是否存在一个值 y，使得 x + y = target。
//             时间复杂度 = O(n^2)
//             空间复杂度 = O(1)
//=======================================================================================

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int * returnNums = (int *)calloc(2, sizeof(int));
    for(int i = 0; i < numsSize - 1; ++i)
    {
        for(int j = i + 1; j < numsSize; ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                returnNums[0] = i;
                returnNums[1] = j;
                *returnSize = 2;
                return returnNums;
            }
        }
    }
    
    return NULL;
}

int main()
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    
    int * returnNums = twoSum(nums, 4, target, &returnSize);
    for(int i = 0; i < returnSize; ++i)
    {
        printf("%d ", returnNums[i]);
    }
    printf("\n");

    free(returnNums);

    return 0;
}

