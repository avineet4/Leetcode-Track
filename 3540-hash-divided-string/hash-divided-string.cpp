class Solution {
public:
    string stringHash(string s, int k) {
        string result = "";
        int i = 0, n = s.size();
        result.reserve(n / k + 1);

        while(i < n) {
            int j = 0;
            for(int x = 0; x < k; ++x) {
                j += s[i + x] - 'a';
            }
            result += ((j % 26) + 'a');
            i += k;
        }

        return result;
    }
};