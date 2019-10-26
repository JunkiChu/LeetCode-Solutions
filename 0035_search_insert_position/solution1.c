//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年10月26日
//   描    述: 二分查找法
//=======================================================================================

/*
 * 经典的二分查找算法, 重点在于确定 return begin 还是 return end
 * 
 * 时间复杂度 = O(log(n))
 * 空间复杂度 = O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int nums_size, int target)
{
    if(NULL == nums || 0 == nums_size)
    {
        return -1;
    }

    int begin = 0;
    int end = nums_size - 1;
    while(begin <= end)
    {
        int middle = (begin + end) / 2;
        if(nums[middle] < target)
        {
            begin = middle + 1;
        }
        else if(nums[middle] > target)
        {
            end = middle - 1;
        }
        else
        {
            return middle;
        }
    }

    return begin;
}

int main()
{
    int nums[4] = { 1, 3, 5, 6 };
    int target = 5;
    printf("%d\n", searchInsert(nums, 4, target));

    target = 2;
    printf("%d\n", searchInsert(nums, 4, target));

    target = 7;
    printf("%d\n", searchInsert(nums, 4, target));

    target = 0;
    printf("%d\n", searchInsert(nums, 4, target));

    return 0;
}

