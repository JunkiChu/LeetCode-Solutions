//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年10月26日
//   描    述: 暴力法
//=======================================================================================

/*
 * 外循环范围i[0, size), 内循环从后往前遍历j[0, i]
 * 通过双层循环，可以穷举所有的子区间，然后再对子区间内的所有元素求和
 * 
 * 时间复杂度 = O(n^2)
 * 空间复杂度 = O(1)
 */ 

#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int nums_size)
{
    int max = nums[0];
    for(int i = 1; i < nums_size; ++i)
    {
        int sum = 0;
        for(int j = i; j >= 0; --j)
        {
            sum += nums[j];
            if(sum > max)
            {
                max = sum;
            }
        }
    }

    return max;
}

int main()
{
    int nums[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    printf("%d\n", maxSubArray(nums, 9));

    return 0;
}

