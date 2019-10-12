//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称：solution1.c
//   创 建 者：Junki Chu <jk.chu@foxmail.com>
//   创建日期：2019年08月24日
//   描    述：类似归并排序将两个有序数组合并为一个有序数组，但不需要真正合并。设置两个索
//             引变量对应 nums1 和 nums2，遍历 size / 2 + 1 次，每次遍历右值赋给左值，并
//             确定一个值存入右值。
//             时间复杂度 = O(m + n)
//             空间复杂度 = O(1)
//=======================================================================================

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int * nums1, int nums1Size, int * nums2, int nums2Size)
{
    int size = nums1Size + nums2Size;
    int index1 = 0;
    int index2 = 0;
    int left = -1;
    int right = -1;

    for(int i = 0; i <= size / 2; ++i)
    {
        left = right;
        
        // 判断第一个数组是否遍历完，若遍历完则确定值为第二个数组的元素
        // 若无遍历完，则判断第二个数组是否遍历完，若遍历完则确定值为第一个数组的元素
        // 若都无遍历完，则比较当前两个数组的元素大小，确定值为较小的元素
        if(index1 < nums1Size && (index2 >= nums2Size || nums1[index1] < nums2[index2]))
        {
            right = nums1[index1++];
        }
        else
        {
            right = nums2[index2++];
        }
    }
    
    if(size % 2 == 0)
    {
        return (left + right) / 2.0;
    }
    else
    {
        return right;
    }
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

