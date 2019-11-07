//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution2.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年10月26日
//   描    述: 动态规划
//=======================================================================================

/*
 * 动态规划思考三步走:
 *     1. 状态: 思考问题最小规模的时候, 是什么情况
 *     2. 状态转移方程: 思考问题规模之间的递推关系, 自下而上
 *     3. 输出: 思考问题最终要输出的结果
 *     
 * 我们先尝试将状态定义为题目要求的结果, 即dp[i]表示nums在区间[0, i]中连续
 * 子数组的最大和, 而这个连续子数组是以区间内某一元素结尾的, 所以这一问题
 * 规模仍可以细分, 即dp[i]表示以nums[i]为结尾的连续子数组的最大和。而输出
 * 便是dp[0], ..., dp[i]的最大值。
 * 
 * 状态转移方程
 * 因为nums[i]一定会被选取, 那么dp[i - 1]的正负就作为分类标准了
 * 即, dp[i] =  dp[i - 1] + nums[i], dp[i - 1] >= 0
 *              nums[i]            , dp[i - 1] < 0
 * 
 * 时间复杂度 = O(n)
 * 空间复杂度 = O(1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX(var1, var2) ((var1) > (var2) ? (var1) : (var2))

int maxSubArray(int* nums, int nums_size)
{
    int sum = nums[0];
    int max = nums[0];
    
    for(int i = 1; i < nums_size; ++i)
    {
        sum = MAX(sum, 0) + nums[i];
        max = MAX(max, sum);
    }

    return max;
}

int main()
{
    int nums[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    printf("%d\n", maxSubArray(nums, 9));

    return 0;
}

