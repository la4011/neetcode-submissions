#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++)
            if (i == matrix.size() -1 || matrix[i + 1][0] > target)
                return binary_search(matrix[i].begin(), matrix[i].end(), target);
    }
};
