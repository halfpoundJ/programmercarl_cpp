//
// Created by Jing Liu on 12.01.24.
//

#ifndef PROGRAMMERCARL_CPP_SPIRAL_MATRIX_II_59_H
#define PROGRAMMERCARL_CPP_SPIRAL_MATRIX_II_59_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int startx = 0;
        int starty = 0;
        int loop = n / 2; // loop numbers
        int mid = n / 2; // middle position of matrix
        int count = 1;
        int offset = 1; // to control the length of edge.
        int i,j;
        while (loop--) {
            i = startx;
            j = starty;
            // first edge, column changes
            for (j = starty; j < n - offset; j++) {
                result[startx][j] = count++;
            }
            // second edge, row changes
            for (i = startx; i < n - offset; i++) {
                result[i][j] = count++;
            }
            // third edge, column changes
            for (; j > starty; j--) {
                result[i][j] = count++;
            }
            // forth edge, row changes
            for (; i > startx; i--) {
                result[i][j] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if (n % 2 == 1) {
            result[mid][mid] = count;
        }
        return result;
    }
};

#endif //PROGRAMMERCARL_CPP_SPIRAL_MATRIX_II_59_H
