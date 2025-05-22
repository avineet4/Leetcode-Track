class Solution {
public:
    int partitionString(string s) {
        int mask = 0;
        int ans = 0;

        for(const char& letter: s) {
            int bit = 1 << (letter - 'a');
            if(mask & bit){
                ans++;
                mask = 0;
            }

            mask |= bit;
        }

        return ++ans;
    }
};