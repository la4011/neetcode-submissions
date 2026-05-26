#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> M;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        M[key].push_back({ timestamp, value });
    }

    string get(string key, int timestamp) {
        auto it = upper_bound(M[key].begin(), M[key].end(), make_pair(timestamp, string(127, 'z')));
        if (it == M[key].begin())
            return "";
        return prev(it)->second;
    }
};
