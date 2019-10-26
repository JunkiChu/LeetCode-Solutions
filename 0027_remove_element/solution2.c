//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年10月26日
//   描    述: 双指针法
//=======================================================================================

/* 
 * 同样设置两个指针i和j, i指向数组最后一个元素的下一个位置, j指向数组第一个元素。
 * 当 val == nums[j] 时, 将最后一个元素复制到当前元素, 并释放最后一个元素, 相当于
 * 数组大小减1, 然后继续对当前元素进行检查;
 * 当 val != nums[j] 时, 递增j, 检查下一元素。
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

    int i = nums_size;
    int j = 0;
    while(j < i)
    {
        if(val == nums[j])
        {
            nums[j] = nums[i - 1];
            --i;
        }
        else
        {
            ++j;
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

