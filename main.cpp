//
// Created by Jing Liu on 26.10.23.
//
#include <iostream>
#include <vector>
#include "practice.h"
#include "minimum_size_subarray_sum_209.h"

using namespace std;

int main() {
    Solution s;
    vector<int> arr = {1,1,1,1,1,1,1,1};
    int result = s.minSubArrayLen(11, arr);
    cout << result << endl;
} 