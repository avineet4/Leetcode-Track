class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 0; i < 32; ++i) {
            bool abit = (a >> i) & 1;
            bool bbit = (b >> i) & 1;
            bool cbit = (c >> i) & 1;

            if ((abit | bbit) != cbit) {
                if (abit == 1 && bbit == 1 && cbit == 0)
                    count += 2;
                else
                    count++;
            }

        }
        return count;
    }
};