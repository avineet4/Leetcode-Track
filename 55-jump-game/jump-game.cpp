class Solution {
public:
    bool helper(vector<int>& nums, unordered_map<int, bool>& memo, int index) {
        if (index >= nums.size() - 1) {
            return true;
        }

        if(memo.find(index) != memo.end()) {
            return memo[index];
        }

        int maxJump = nums[index];
        for(int i = 1; i <= maxJump; ++i){
            if (helper(nums, memo, index + i)) {
                memo[index] = true;
                return true;
            }
        }

        memo[index] = false;
        return false;
    }

    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> memo = {};

        return helper(nums, memo, 0);
    }
};