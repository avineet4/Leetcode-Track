class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;

        for(int i = 1, j = 0; i <= n && j < target.size() ; ++i) {
            if(i == target[j]) {
                result.push_back("Push");
                j++;
            } else if (i < target[j]){
                result.push_back("Push");
                result.push_back("Pop");
            } else {
                break;
            }
        }

        return result;
    }
};