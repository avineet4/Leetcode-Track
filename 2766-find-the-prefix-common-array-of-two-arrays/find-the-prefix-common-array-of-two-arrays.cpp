class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> seen(50, 0);
        int count = 0;

        for(int i = 0; i < A.size(); ++i) {
            if(seen[A[i] - 1] == 0) {
                seen[A[i] - 1] = 1;
            } else {
                count++;
            }

            if(seen[B[i] - 1] == 0) {
                seen[B[i] - 1] = 1;
            } else {
                count++;
            }

            A[i] = count;
        }

        return A;
    }
};