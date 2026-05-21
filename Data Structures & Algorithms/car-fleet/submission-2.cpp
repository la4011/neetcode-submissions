#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++)
            cars.push_back({ position[i], speed[i] });

        sort(cars.begin(), cars.end());

        int fleet = 0;
        double M = 0.0;

        for (int i = cars.size() - 1; i >= 0; i--)
        {
            double cur = (double)(target - cars[i].first) / cars[i].second;

            if (cur > M)
            {
                fleet++;
                M = cur;
            }
        }
        return fleet;
    }
};
