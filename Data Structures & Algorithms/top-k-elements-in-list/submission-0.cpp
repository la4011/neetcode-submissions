class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int minus[1001] = {0,};
        int zero = 0;
        int plus[1001] = {0,};
        vector<pair<int,int>> tmp;
        vector<int> sol;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
                minus[abs(nums[i])]++;
            else if(nums[i]==0)
                zero++;
            else
                plus[nums[i]]++;
        }

        tmp.push_back({zero, 0});
        for(int i = 1; i <= 1000; i++)
        {
            tmp.push_back({minus[i], -i});
            tmp.push_back({plus[i], i});
        }

        sort(tmp.begin(), tmp.end());

        for(int i = tmp.size() - 1; i >= 0; i--)
        {
            sol.push_back(tmp[i].second);
            if(sol.size() >= k)
                return sol;
        }
    }
};
