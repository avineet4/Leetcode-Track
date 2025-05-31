class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = (n * (n + 1)) >> 1;
        int k = n / m;
        int mSum = (m * k * (k + 1)) >> 1;

        return total - (mSum << 1);
    }
};