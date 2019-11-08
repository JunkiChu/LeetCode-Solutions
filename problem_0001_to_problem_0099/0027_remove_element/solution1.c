//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年10月26日
//   描    述: 双指针法
//=======================================================================================

/*
 * 设置两个指针i和j, i是慢指针, j是快指针, 当 nums[j] == val 时, 递增j,
 * 当 nums[j] != val 时, 复制 nums[j] 到 nums[i], 递增i和j。重复这一过
 * 程, 直到j到达数组末尾, 返回新数组的长度为i。
 * 
 * 时间复杂度 = O(n)
 * 空间复杂度 = O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int nums_size, int val)
{
    if(NULL == nums || 0 == nums_size)
    {
        return 0;
    }

    int i = 0;
    for(int j = 0; j < nums_size; ++j)
    {
        if(val != nums[j])
        {
            nums[i++] = nums[j];
        }
    }

    return i;
}

int main()
{
    int nums1[4] = { 3, 2, 2, 3 };
    int val1 = 3;
    int len1 = removeElement(nums1, 4, val1);
    printf("%d\n", len1);
    for(int i = 0; i < len1; ++i)
    {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    int nums2[8] = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val2 = 2;
    int len2 = removeElement(nums2, 8, val2);
    printf("%d\n", len2);
    for(int i = 0; i < len2; ++i)
    {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return 0;
}

