class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(26, 0);

        for(const auto& letter : s) {
            map[letter - 'a']++;
        }

        for(int i = 0; i < s.size(); ++i) {
            if(map[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};