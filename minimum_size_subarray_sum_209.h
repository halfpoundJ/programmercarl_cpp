//
// Created by Jing Liu on 12.01.24.
//

#ifndef PROGRAMMERCARL_CPP_MINIMUM_SIZE_SUBARRAY_SUM_209_H
#define PROGRAMMERCARL_CPP_MINIMUM_SIZE_SUBARRAY_SUM_209_H

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // sum of all numbers in sliding window
        int i = 0; // start position of sliding window
        int subLength = 0; // length of sliding window
        for (int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while (sum >= target) { // here we use while because everytime when we move i, the judging condition should be checked.
                subLength = j - i + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[i]; // sliding window moves.
                i++; // sliding window moves.
            }
        }
        return result == INT32_MAX ? 0 : result; // if there's no such subarray, return 0.
    }
};

#endif //PROGRAMMERCARL_CPP_MINIMUM_SIZE_SUBARRAY_SUM_209_H
