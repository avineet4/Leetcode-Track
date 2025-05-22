class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        vector<bool> group(26, 0);

        int ans = 0;

        for(int i = 0; i < n; ++i) {
            if(group[s[i] - 'a']){
                ans++;
                fill(group.begin(), group.end(), 0);
            }

            group[s[i] - 'a'] = 1;
        }

        return ++ans;
    }
};