//
// Created by Jing Liu on 26.10.23.
//
#include <iostream>
#include <vector>
#include "spiral_matrix_II_59.h"

using namespace std;

int main() {
    Solution s;
    vector<int> nums = {2,3,1,2,4,3};
    int n = 3;
    int result = s.generateMatrix(n);
    cout << result << endl;
    return 0;
}