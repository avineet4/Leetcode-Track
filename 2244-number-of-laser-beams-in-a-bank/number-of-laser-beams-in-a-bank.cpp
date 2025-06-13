class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0;
        int prev = 0;

        for(int i = 0; i < bank.size(); ++i) {
            int count1 = 0;
            for(const auto& letter : bank[i]) {
                if(letter == '1') count1++;
            }

            if(count1 != 0) {
                result += prev * count1;
                prev = count1;
            }
        }

        return result;
    }
};