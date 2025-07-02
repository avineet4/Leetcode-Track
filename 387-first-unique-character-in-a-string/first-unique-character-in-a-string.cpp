class Solution {
public:
    int firstUniqChar(string s) {
        unsigned int seen_once = 0;
        unsigned int seen_multiple = 0;

        for (char c : s) {
            int idx = c - 'a';
            unsigned int mask = (1U << idx);

            if (!(seen_once & mask)) {
                seen_once |= mask;
            } else {
                seen_multiple |= mask;
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            unsigned int mask = (1U << idx);
            if ((seen_once & mask) && !(seen_multiple & mask)) {
                return i;
            }
        }

        return -1;
    }
};