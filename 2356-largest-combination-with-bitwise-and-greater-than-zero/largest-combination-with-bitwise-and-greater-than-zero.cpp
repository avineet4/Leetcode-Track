class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int arr[24] = {0};
        int maxEl = 0;

        for(const int& candidate: candidates){
            for(int i = 0; i < 24; ++i) {
                arr[i] += ((candidate & (1 << i)) ? 1 : 0);
                maxEl = max(maxEl, arr[i]);
            }
        }

        return maxEl;
    }
};