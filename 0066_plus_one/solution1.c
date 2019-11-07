//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution1.c
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年11月07日
//   描    述: 数组遍历
//=======================================================================================

/*
 * 当前位数为9时, 有进位发生, 否则直接加1
 * 
 * 分为三种情况:
 * 1. 末位无进位, 直接在末位加1即可, 如 123 -> 124
 * 2. 末位有进位, 在中间位置进位停止, 则当前位后为0, 当前位加1, 如 899 -> 900
 * 3. 末位有进位, 并且在第一位仍要进位, 唯一的情形就是全为9, 需要重新分配空间, 如 999 -> 1000
 * 
 * 时间复杂度 = O(n)
 * 空间复杂度 = O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    for(int i = digitsSize - 1; i >= 0; --i)
    {
        if(9 != digits[i])
        {
           ++digits[i];
           *returnSize = digitsSize;
           break;
        }
        
        digits[i] = 0;
    }

    if(0 == digits[0])
    {
        digits = (int*)realloc(digits, (digitsSize + 1) << 2);
        digits[0] = 1;
        digits[digitsSize] = 0;
        *returnSize = digitsSize + 1;
    }

    return digits;
}

int main()
{
    int* digits1 = (int*)calloc(3, sizeof(int));
    digits1[0] = 1;
    digits1[1] = 2;
    digits1[2] = 3;
    
    int returnSize1 = 0;
    int* returnArray1 = plusOne(digits1, 3, &returnSize1);
    for(int i = 0; i < returnSize1; ++i)
    {
        printf("%d", returnArray1[i]);
    }
    printf("\n");
    free(digits1);
    free(returnArray1);

    int* digits2 = (int*)calloc(4, sizeof(int));
    digits2[0] = 4;
    digits2[1] = 3;
    digits2[2] = 2;
    digits2[3] = 1;
    
    int returnSize2 = 0;
    int* returnArray2 = plusOne(digits2, 4, &returnSize2);
    for(int i = 0; i < returnSize2; ++i)
    {
        printf("%d", returnArray2[i]);
    }
    printf("\n");
    free(digits2);
    free(returnArray2);

    int* digits3 = (int*)calloc(5, sizeof(int));
    digits3[0] = 9;
    digits3[1] = 9;
    digits3[2] = 9;
    digits3[3] = 9;
    digits3[4] = 9;
    
    int returnSize3 = 0;
    int* returnArray3 = plusOne(digits3, 5, &returnSize3);
    for(int i = 0; i < returnSize3; ++i)
    {
        printf("%d", returnArray3[i]);
    }
    printf("\n");
    free(digits3);
    free(returnArray3);

    return 0;
}

