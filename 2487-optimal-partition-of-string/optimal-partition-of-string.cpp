class Solution {
public:
    int partitionString(string s) {
        vector<bool> group(26, 0);
        int ans = 0;

        for(const char& letter: s) {
            if(group[letter - 'a']){
                ans++;
                fill(group.begin(), group.end(), 0);
            }

            group[letter - 'a'] = 1;
        }

        return ++ans;
    }
};