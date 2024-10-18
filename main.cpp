//
// Created by Jing Liu on 26.10.23.
//
#include <iostream>
#include <vector>
#include "squares_of_a_sorted_array_977_backup.h"

using namespace std;

int main() {
    Solution_2 s;
    vector<int> nums = {-4, 3, 8, 18, 20};
    vector<int> result = s.return_square_array(nums);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << ' ';
    }
    return 0;
}