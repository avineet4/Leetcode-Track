class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char letter : n){
            ans = max(ans, letter - '0');
        }
        return ans;
    }
};