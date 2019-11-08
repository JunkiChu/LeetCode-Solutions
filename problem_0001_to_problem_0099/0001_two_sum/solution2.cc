//=======================================================================================
//   Copyright (C) 2019 Junki Chu. All rights reserved.
//   
//   文件名称: solution2.cc
//   创 建 者: Junki Chu <jk.chu@foxmail.com>
//   创建日期: 2019年08月24日
//   描    述: 哈希表
//=======================================================================================

/*
 * 遍历数组, 在哈希表中查找当前元素所对应的目标元素是否存在, 若存在则返回,
 * 若不存在则将当前元素放入哈希表中
 * 
 * 时间复杂度 = O(n)
 * 空间复杂度 = O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash_map;
        
        for(size_t i = 0; i < nums.size(); ++i)
        {
            auto it = hash_map.find(target - nums[i]);
            if(hash_map.end() == it)
            {
                hash_map[nums[i]] = i;
            }
            else
            {
                return vector<int>({ it->second, static_cast<int>(i) });
            }
        }
        
        return vector<int>();
    }
};

int main()
{
    vector<int> nums({ 2, 7, 11, 15 });
    int target = 9;

    Solution solution;
    for(auto num : solution.twoSum(nums, target))
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

