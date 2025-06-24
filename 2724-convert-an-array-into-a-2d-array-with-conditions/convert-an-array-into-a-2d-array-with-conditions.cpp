class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxFreq = 0;
        unordered_map<int, int> freq;

        for(const int& num : nums) {
            maxFreq = max(maxFreq, ++freq[num]);
        }
        
        vector<vector<int>> result(maxFreq);

        for (auto& [num, count] : freq) {
            for (int i = 0; i < count; ++i) {
                result[i].push_back(num);
            }
        }

        return result;
    }
};