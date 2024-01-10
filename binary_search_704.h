//
// Created by Jing Liu on 26.10.23.
//

#ifndef PROGRAMMERCARL_CPP_BINARY_SEARCH_704_H
#define PROGRAMMERCARL_CPP_BINARY_SEARCH_704_H

#include "iostream"
#include "vector"

using namespace std;

// 左闭右闭法
class Solution_1 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // index starts from 0
        while (left <= right) {
            int middle = left + (right - left) / 2; // avoid integer overflow
            if (target < nums[middle]) { // cannot include equal sign
                right = middle - 1; // target is in the left interval of array (left side of the middle point) --> target in [left, middle - 1]
            } else if (target > nums[middle]) { // cannot include equal sign
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};

// 左闭右开法
class Solution_2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) { // can not include equal sign. when left == right, the interval [left,right) is invalid
            int middle = left + (right - left) / 2; //
            if (target < nums[middle]) {
                right = middle; //
            } else if (target > nums[middle]) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};

#endif //PROGRAMMERCARL_CPP_BINARY_SEARCH_704_H
