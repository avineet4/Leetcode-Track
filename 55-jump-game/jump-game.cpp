class Solution {
public:
    enum State {
        UNKNOWN,
        GOOD,
        BAD
    };

    bool helper(vector<int>& nums, vector<State>& memo, int index) {
        if (index >= nums.size() - 1) {
            return true;
        }

        if (memo[index] != UNKNOWN) {
            return memo[index] == GOOD;
        }

        int maxJump = nums[index];
        for(int i = 1; i <= maxJump; ++i){
            if (helper(nums, memo, index + i)) {
                memo[index] = GOOD;
                return true;
            }
        }

        memo[index] = BAD;
        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<State> memo(n, UNKNOWN);

        return helper(nums, memo, 0);
    }
};