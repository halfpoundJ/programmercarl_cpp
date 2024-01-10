//
// Created by Jing Liu on 26.10.23.
//

#ifndef PROGRAMMERCARL_CPP_REMOVE_ELEMENT_27_H
#define PROGRAMMERCARL_CPP_REMOVE_ELEMENT_27_H

#include "iostream"
#include "vector"

using namespace std;

//暴力解法
class Solution_1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(unsigned i = 0; i < size; ++i){
            if(nums[i] == val){
                for(unsigned j = i + 1; j < nums.size(); ++j){
                    nums[j - 1] = nums[j];
                }
                size--;
                i--;
            }
        }
        return size;
    }
};

//双指针法
class Solution_2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0; // define low pointer.
        for(int fast = 0; fast < nums.size(); ++fast){
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

#endif //PROGRAMMERCARL_CPP_REMOVE_ELEMENT_27_H
