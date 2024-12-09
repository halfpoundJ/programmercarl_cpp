//
// Created by Jing Liu on 26.10.23.
//
#include <iostream>
#include <vector>
#include "binary_search_704.h"

using namespace std;

int main() {
    Solution_1 s;
    int result = 0;
    vector<int> arr = {1, 2, 3, 4, 5};
    result = s.search(arr, 4);
    cout << result << endl;
    return 0;
} 