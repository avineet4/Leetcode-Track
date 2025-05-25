class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> seen;

        for(const int& num : nums2) {
            while(!seen.empty() && seen.top() < num) {
                map[seen.top()] = num;
                seen.pop();
            }
            seen.push(num);
        }

        vector<int> output;
        for(const int& num : nums1) {
            output.push_back(map.count(num) ? map[num] : -1);
        }

        return output;
    }
};