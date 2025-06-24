class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int mostFreq = 0;
        unordered_map<int, int> freq;

        for(const int& num : nums) {
            freq[num]++;
            if(freq[num] > mostFreq) {
                mostFreq = freq[num];
            }
        }
        
        vector<vector<int>> result;

        for(int i = 0; i < mostFreq; ++i) {
            vector<int> row;
            for(auto& it : freq){
                if(it.second > 0) {
                    row.push_back(it.first);
                    it.second--;
                }
            }
            result.push_back(row);
        }

        return result;
    }
};