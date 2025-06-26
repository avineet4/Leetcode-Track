class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        string token1, token2;

        while (ss1.good() || ss2.good()) {
            int num1 = 0, num2 = 0;

            if (getline(ss1, token1, '.'))
                num1 = stoi(token1);
            if (getline(ss2, token2, '.'))
                num2 = stoi(token2);

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }

        return 0;
    }
};