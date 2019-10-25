//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution3.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年10月25日
//   描    述: 二分查找法
//=======================================================================================

/*
 * 同样采用二分查找思想, 区别是在数组中加入了虚位, 使得单个数组长度恒为奇数,
 * 数组总长度恒为偶数, 减少代码量
 * 
 * Eg: [ 1, 4, 7, 9 ] --> [ #, 1, #, 4, #, 7, #, 9, # ]
 *     [ 2, 3, 5 ] --> [ #, 2, #, 3, #, 5, # ]
 * cut = 4
 * LMax = nums[(cut - 1) / 2] --> nums[1] = 4
 * RMin = nums[cut / 2] --> nums[2] = 7
 * 
 * 时间复杂度 = O(log(n))
 * 空间复杂度 = O(1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

    int nums1_left_max = 0, nums2_left_max = 0;     // 两个数组分割后的左半部最大值
    int nums1_right_min = 0, nums2_right_min = 0;   // 两个数组分割后的右半部最小值
    int cut1 = 0, cut2 = 0;                         // 两个数组的分割点
    int begin = 0, end = nums1_size * 2 + 1;        // 加入了虚位, 数组长度为2m + 1, 总长度为2m + 2n + 2
    while(begin <= end)
    {
        cut1 = (begin + end) / 2;
        cut2 = nums1_size + nums2_size - cut1;

        // 临界点判断
        nums1_left_max = (0 == cut1 ? INT_MIN : nums1[(cut1 - 1) / 2]);
        nums2_left_max = (0 == cut2 ? INT_MIN : nums2[(cut2 - 1) / 2]);
        nums1_right_min = (nums1_size * 2 == cut1 ? INT_MAX : nums1[cut1 / 2]);
        nums2_right_min = (nums2_size * 2 == cut2 ? INT_MAX : nums2[cut2 / 2]);
        
        if(nums2_left_max > nums1_right_min)
        {
            begin = cut1 + 1;
        }
        else if(nums1_left_max > nums2_right_min)
        {
            end = cut1 - 1;
        }
        else
        {
            break;
        }
    }

    return (MAX(nums1_left_max, nums2_left_max) + MIN(nums1_right_min, nums2_right_min)) / 2.0;
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

