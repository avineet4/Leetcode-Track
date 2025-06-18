class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int size = garbage.size();
        int lastG = -1, lastP = -1, lastM = -1;
        int countG = 0, countP = 0, countM = 0;

        for(int i = size - 1; i >= 0; --i) {
            if(lastG == -1 || lastP == -1 || lastM == -1) {
                for(const char& ch : garbage[i]) {
                    if(ch == 'G' && lastG == -1) lastG = i - 1;
                    else if(ch == 'P' && lastP == -1) lastP = i - 1;
                    else if(ch == 'M' && lastM == -1) lastM = i - 1;
                }
            }

            for(const char& ch : garbage[i]) {
                if(ch == 'G') countG++;
                else if(ch == 'P') countP++;
                else if(ch == 'M') countM++;
            }

        }

        int result = countG + countP + countM;

        for(const int& time : travel) {
            result += (lastG >= 0) ? time : 0;
            lastG--;
            result += (lastP >= 0) ? time : 0;
            lastP--;
            result += (lastM >= 0) ? time : 0;
            lastM--;
        }

        return result;
    }
};