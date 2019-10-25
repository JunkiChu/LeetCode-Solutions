//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年10月25日
//   描    述: 双指针法
//=======================================================================================

/*
 * 在已排序的数组, 放置一个快慢两个指针, 当两个指针指向的值相等时, 快指针递增
 * 当值不相等时, 将快指针指向的值覆盖慢指针指向的值, 快慢指针各自递增, 重复过
 * 程直到快指针到达末尾
 * 
 * 时间复杂度 = O(n)
 * 空间复杂度 = O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int nums_size)
{
    if(NULL == nums || 0 == nums_size)
    {
        return 0;
    }

    int len = 0;
    for(int i = 0; i < nums_size; ++i)
    {
        if(nums[len] != nums[i])
        {
            nums[++len] = nums[i];
        }
    }

    return len + 1;
}

int main()
{
    int nums1[3] = { 1, 1, 2 };
    int len1 = removeDuplicates(nums1, 3);
    printf("%d\n", len1);
    for(int i = 0; i < len1; ++i)
    {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    int nums2[10] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int len2 = removeDuplicates(nums2, 10);
    printf("%d\n", len2);
    for(int i = 0; i < len2; ++i)
    {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return 0;
}

