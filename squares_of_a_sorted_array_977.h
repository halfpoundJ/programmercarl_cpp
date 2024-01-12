//
// Created by Jing Liu on 11.01.24.
//

#ifndef PROGRAMMERCARL_CPP_SQUARES_OF_A_SORTED_ARRAY_977_H
#define PROGRAMMERCARL_CPP_SQUARES_OF_A_SORTED_ARRAY_977_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力法，用了sort函数进行快排。
class Solution_1{
public:
    vector<int> sortedSquares(vector<int>& nums){
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// 使用双指针。
class Solution_2{
public:
    vector<int> sortedSquares(vector<int>& nums){
        int k = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j;){
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[k--] = nums[j] * nums[j];
                j--;
            } else {
                result[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};

#endif //PROGRAMMERCARL_CPP_SQUARES_OF_A_SORTED_ARRAY_977_H
