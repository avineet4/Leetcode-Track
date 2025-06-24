class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string result = "1";

        for(int i = 2; i <= n; ++i) {
            ostringstream oss;
            int count = 1;
            for(int j = 1; j < result.size(); ++j) {
                if(result[j] == result[j - 1]) {
                    count++;
                } else {
                    oss << count << result[j - 1];
                    count = 1;
                }
            }
            oss << count << result.back();
            result = oss.str();
        }

        return result;
    }
};