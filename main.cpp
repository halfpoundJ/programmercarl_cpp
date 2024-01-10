//
// Created by Jing Liu on 26.10.23.
//
#include <iostream>
#include <vector>
#include "remove_element_27.h"

using namespace std;

int main() {
    Solution_2 s;
    vector<int> nums = {1, 2, 3, 4, 5, 4};
    int target = 4;
    int result = s.removeElement(nums, target);
    cout << result << endl;
    return 0;
}