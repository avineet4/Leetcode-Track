class Solution {
public:
    int firstUniqChar(string s) {
        bitset<26> seen_once;
        bitset<26> seen_multiple;

        for (char c : s) {
            int idx = c - 'a';
            if (!seen_once[idx]) {
                seen_once.set(idx);
            } else {
                seen_multiple.set(idx);
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (seen_once[idx] && !seen_multiple[idx]) {
                return i;
            }
        }

        return -1;
    }
};