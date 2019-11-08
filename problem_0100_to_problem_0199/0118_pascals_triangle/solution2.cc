//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution2.cc
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年11月08日
//   描    述: 动态规划
//=======================================================================================

/*
 * 非常简单的算法实现, 根据上一行来构造每一行
 * 首先, 我们先生成整个 triangle 列表, 每一行的第一个元素和最后一个元素存入 1,
 * 中间的第 n 个元素由上一行的第 n - 1 和第 n 个元素相加而得
 * 
 * 时间复杂度 = O(n^2)
 * 空间复杂度 = O(n^2)
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle(numRows);
        for(int i = 0; i < numRows; ++i)
        {
            vector<int> row(i + 1, 1);
            for(int j = 1; j < i; ++j)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle[i] = row;
        }
        return triangle;
    }
};

int main()
{
    Solution s;
    auto triangle = s.generate(5);
    for(auto &i : triangle)
    {
        for(auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

