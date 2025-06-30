class Solution {
public:
    static bool compare(int &a, int &b) {
        string A = to_string(a);
        string B = to_string(b);

        return A + B > B + A;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);

        if (nums[0] == 0) return "0";

        string result = "";

        for(const auto& num : nums) {
            result += to_string(num);
        }

        return result;
    }
};