class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for(int i = 0; i < 24; ++i){
            int count = 0;
            for(const auto& candidate: candidates) {
                if(candidate & (1 << i)){
                    count++;
                }
            }
            res = max(res, count); 
        }

        return res;
    }
};