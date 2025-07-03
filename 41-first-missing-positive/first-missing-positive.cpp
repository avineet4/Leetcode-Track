class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(auto& num : nums){
            if(num < 0) {
                num = 0;
            }
        }

        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            if(nums[i] == INT_MAX) continue;
            int val = abs(nums[i]);

            if (val >= 1 && val <= n) {
                if (nums[val - 1] == 0) nums[val - 1] = INT_MAX;
                if (nums[val - 1] > 0) nums[val - 1] *= -1;
            }
        }

        int i;

        for(i = 0; i < n; ++i) {
            if(nums[i] >= 0 || nums[i] == INT_MAX){
                return i + 1;
            }
        }

        return i + 1;
    }
};