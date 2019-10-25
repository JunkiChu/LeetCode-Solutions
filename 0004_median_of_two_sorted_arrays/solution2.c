//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution2.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年10月25日
//   描    述: 二分查找法
//=======================================================================================

/*
 * 根据中位数的特点: 
 * 将一个集合划分为两个长度相等的子集, 其中一个子集中的元素总是大于另一个子集中的元素
 * 
 * 分别将数组A和B各分成左右两部分, 使得
 * -> len(left_partA + left_partB) = len(right_partA + left_partB)
 * -> len(left_part) = len(right_part)      --- 1
 * 另 max(left_part) <= min(right_part)     --- 2
 * 
 * 要确保中位数的这两个条件
 * 只需在[0, len(A)]中使用二分查找法找到目标值i, 使得
 *      A[i - 1] <= B[j] && A[i] >= B[j - 1]
 * 其中j = (len(A) + len(B) + 1) / 2 - i, len(A) <= len(B)
 * (分割线位于i/j的左边)
 * 
 * 时间复杂度 = O(log(n))
 *     二分查找的特点: 每次查找区间的长度都会减少为原来的一半
 *     所以只需执行log(n)次循环即可找到目标值
 * 空间复杂度 = O(1)
 */ 

#include <stdio.h>
#include <stdlib.h>

#define SWAP(_type_, var1, var2) { _type_ temp = (var1); (var1) = (var2); (var2) = temp; }
#define MIN(var1, var2) ((var1) < (var2) ? (var1) : (var2))
#define MAX(var1, var2) ((var1) > (var2) ? (var1) : (var2))

double findMedianSortedArrays(int *nums1, int nums1_size, int *nums2, int nums2_size)
{
    if(nums1_size > nums2_size)
    {
        // 确保nums1的长度小于等于nums2的长度
        SWAP(int*, nums1, nums2);
        SWAP(int, nums1_size, nums2_size);
    }

    int begin = 0;
    int end = nums1_size;
    int half_size = (nums1_size + nums2_size + 1) / 2;
    while(begin <= end)
    {
        int i = (begin + end) / 2;
        int j = half_size - i;
        if(i < end && nums1[i] < nums2[j - 1])
        {
            // i太小的情况
            begin = i + 1;
        }
        else if(i > begin && nums1[i - 1] > nums2[j])
        {
            // i太大的情况
            end = i - 1;
        }
        else
        {
            // i是完美的情况
            // 先计算左半部最大值
            int left_max = 0;
            if(0 == i)
            {
                // nums1数组整体在右半部
                left_max = nums2[j - 1];
            }
            else if(0 == j)
            {
                // nums2数组整体在右半部
                left_max = nums1[i - 1];
            }
            else
            {
                left_max = MAX(nums1[i - 1], nums2[j - 1]);
            }

            // 若总长度是奇数, 则直接返回
            if((nums1_size + nums2_size) % 2 == 1)
            {
                return left_max;
            }

            // 若总长度是偶数, 则计算右半部最小值
            int right_min = 0;
            if(nums1_size == i)
            {
                // nums1数组整体在左半部
                right_min = nums2[j];
            }
            else if(nums2_size == j)
            {
                // nums2数组整体在左半部
                right_min = nums1[i];
            }
            else
            {
                right_min = MIN(nums1[i], nums2[j]);
            }

            return (left_max + right_min) / 2.0;
        }
    }

    return 0.0;
}

int main()
{
    double ret;

    int a[2] = {1, 3};
    int b[1] = {2};
    ret = findMedianSortedArrays(a, 2, b, 1);
    printf("%lf\n", ret);

    int c[2] = {1, 2};
    int d[2] = {3, 4};
    ret = findMedianSortedArrays(c, 2, d, 2);
    printf("%lf\n", ret);

    return 0;
}

