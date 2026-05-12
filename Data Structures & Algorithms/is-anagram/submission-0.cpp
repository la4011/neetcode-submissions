class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            cout << false;
            return 0;
        }

        int cal1[27] = {0,};
        int cal2[27] = {0,};
        for(int i = 0; i < s.size(); i++)
        {
            cal1[s[i]-'a']++;
            cal2[t[i]-'a']++;
        }

        for(int i = 0; i < 26; i++)
            if(cal1[i] != cal2[i])
            {
                cout << false;
                return 0;
            }

        cout << true;
        return 1;
    }
};
