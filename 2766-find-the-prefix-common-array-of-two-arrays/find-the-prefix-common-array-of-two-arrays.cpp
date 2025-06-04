class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        uint64_t seen = 0;
        int count = 0;

        for(int i = 0; i < A.size(); ++i) {
            if(!(seen & (1ULL << A[i]))) {
                seen |= (1ULL << A[i]);
            } else {
                count++;
            }

            if(!(seen & (1ULL << B[i]))) {
                seen |= (1ULL << B[i]);
            } else {
                count++;
            }

            A[i] = count;
        }

        return A;
    }
};