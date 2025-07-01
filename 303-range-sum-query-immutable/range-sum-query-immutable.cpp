class NumArray {
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = vector<int>(nums.size() + 1, 0);

        for(int i = 1; i < this->nums.size(); i++) {
            this->nums[i] += this->nums[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return nums[right + 1] - nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */