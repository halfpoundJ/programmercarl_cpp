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

// use while
class Solution_3{
public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> result = nums;
        int left = 0;
        int right = nums.size() - 1;
        int k = right;
        while(k >= 0) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                result[k] = nums[left] * nums[left];
                k--;
                left++;
            } else {
                result[k] = nums[right] * nums[right];
                k--;
                right--;
            }
        }
        return result;  
    }
};

#endif //PROGRAMMERCARL_CPP_SQUARES_OF_A_SORTED_ARRAY_977_H
