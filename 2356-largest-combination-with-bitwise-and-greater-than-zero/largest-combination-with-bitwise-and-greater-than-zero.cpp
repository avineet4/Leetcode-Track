class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        //In this question size of subset whould be largest not the resut;
        int arr[24] = {0};

        for(const int& candidate: candidates){
            for(int i = 0; i < 24; ++i) {
                arr[i] += (candidate >> i) & 1;
            }
        }

        return *max_element(arr, arr + 24);
    }
};