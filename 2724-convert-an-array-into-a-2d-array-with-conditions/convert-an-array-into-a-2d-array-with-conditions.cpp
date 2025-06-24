class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> frequency(nums.size() + 1, 0);
        vector<vector<int>> result;

        for(int& num : nums) {
            int count = frequency[num]++;
            if(count >= result.size()) {
                result.push_back({});
            }

            result[count].push_back(num);
        }

        return result;
    }
};