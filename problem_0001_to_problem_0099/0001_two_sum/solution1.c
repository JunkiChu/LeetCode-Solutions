//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年08月24日
//   描    述: 暴力法
//=======================================================================================

/*
 * 遍历每个元素x, 查找是否存在一个值y, 使得(x + y = target)
 * 
 * 时间复杂度 = O(n^2)
 * 空间复杂度 = O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int nums_size, int target, int* return_size)
{
    int * return_nums = (int *)calloc(2, sizeof(int));
    for(int i = 0; i < nums_size - 1; ++i)
    {
        for(int j = i + 1; j < nums_size; ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                return_nums[0] = i;
                return_nums[1] = j;
                *return_size = 2;
                return return_nums;
            }
        }
    }
    
    return NULL;
}

int main()
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int return_size;
    
    int * return_nums = twoSum(nums, 4, target, &return_size);
    for(int i = 0; i < return_size; ++i)
    {
        printf("%d ", return_nums[i]);
    }
    printf("\n");

    free(return_nums);

    return 0;
}

