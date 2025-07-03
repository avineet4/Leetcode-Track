class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> seen;

        for(const auto& num : nums) {
            if (num > 0) {
                seen.insert(num);
            }
        }

        int i = 1;
        while(true){
            if(seen.find(i) == seen.end()) {
                return i;
            }
            i++;
        }

        return -1;
    }
};