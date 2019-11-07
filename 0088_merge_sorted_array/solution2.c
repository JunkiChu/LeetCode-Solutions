//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution2.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年11月07日
//   描    述: 双指针法, 从后往前
//=======================================================================================

/*
 * 双指针法从前往后改写 nums1 时, 需要额外空间来存储 nums1 的元素
 * 由于 nums1 的尾部没有任何信息, 采用从后往前的方法就不需要额外空间了
 * 将指针 p1 指向 nums1 有效信息的尾部, 指针 p2 指向 nums2 有效信息的尾部
 * 从后往前将最大值放入 nums1 的尾部
 * 
 * 时间复杂度 = O(m + n)
 * 空间复杂度 = O(1)
 */

#include <stdio.h>
#include <stdlib.h>

#define COPY(dest, beg, src, from, to)\
{ for(int i = (from), j = (beg); i < (to); ++i, ++j) (dest)[j] = (src)[i]; }

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int p = nums1Size - 1, p1 = m - 1, p2 = n - 1;
    while(p1 >= 0 && p2 >= 0)
    {
        nums1[p--] = nums1[p1] >= nums2[p2] ? nums1[p1--] : nums2[p2--];
    }
    
    if(p2 >= 0)
    {
        COPY(nums1, 0, nums2, 0, p2);
    }
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

