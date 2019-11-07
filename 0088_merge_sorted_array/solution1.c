//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年11月07日
//   描    述: 双指针法, 从前往后
//=======================================================================================

/*
 * 对于有序数组, 首先应该想到双指针法
 * 将 p1 置为 nums1 的开头, p2 置为 nums2 的开头, 每一步将最小值放入输出数组中
 * 但由于 nums1 作为输出数组, 需要将 nums1 的前 m 个元素放在其他临时数组中,
 * 所以需要 O(m) 的空间复杂度。
 * 
 * 时间复杂度 = O(m + n)
 * 空间复杂度 = O(m)
 */

#include <stdio.h>
#include <stdlib.h>
#define COPY(dest, beg, src, from, to)\
{ for(int i = (from), j = (beg); i < (to); ++i, ++j) (dest)[j] = (src)[i]; }

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* nums1_copy = (int*)calloc(m, sizeof(int));
    COPY(nums1_copy, 0, nums1, 0, m);
    
    int p = 0, p1 = 0, p2 = 0;
    while(p1 < m && p2 < n)
    {
        nums1[p++] = nums1_copy[p1] <= nums2[p2] ? nums1_copy[p1++] : nums2[p2++];
    }

    if(p1 < m)
    {
        COPY(nums1, p, nums1_copy, p1, m);
    }
    else
    {
        COPY(nums1, p, nums2, p2, n);
    }

    free(nums1_copy);
}

int main()
{
    int nums1[6] = { 1, 2, 3, 0, 0, 0 };
    int nums2[3] = { 2, 5, 6 };
    merge(nums1, 6, 3, nums2, 3, 3);
    for(int i = 0; i < 6; ++i)
    {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}

