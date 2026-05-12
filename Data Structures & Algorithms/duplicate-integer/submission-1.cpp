class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] == nums[i])
            {
                cout << true;
                return 1;
            }
        }
        cout << false;
        return 0;
    }
};