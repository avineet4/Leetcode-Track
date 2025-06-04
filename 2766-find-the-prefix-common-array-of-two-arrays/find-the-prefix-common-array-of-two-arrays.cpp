class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //using bitset to mark the seen elements
        uint64_t seen = 0;
        int count = 0;

        for(int i = 0; i < A.size(); ++i) {
            for (int x : {A[i], B[i]}) {
                if (seen & (1ULL << x)) {
                    count++;
                } else {
                    seen |= (1ULL << x);
                }
            }

            A[i] = count;
        }

        return A;
    }
};