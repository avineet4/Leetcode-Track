class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }

        unsigned int uXorSum = static_cast<unsigned int>(xorSum);
        int rightMostSetBit = static_cast<int>(uXorSum & -uXorSum);

        int x = 0, y = 0;
        for (int num : nums) {
            if (num & rightMostSetBit)
                x ^= num;
            else
                y ^= num;
        }

        return x < y ? vector<int>{x, y} : vector<int>{y, x};
    }
};