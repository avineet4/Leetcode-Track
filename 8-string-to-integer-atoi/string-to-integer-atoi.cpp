class Solution {
public:
    int myAtoi(string str) {
        long result = 0, sign = 1, i = 0;

        while(str[i] == ' ') {
            i++;
            
        }

        if(str[i] == '-') {
            sign = -1;
            i++;
        } else if(str[i] == '+') i++;

        while(str[i] == '0') {
            i++;
            
        }

        for(; i < str.length(); ++i) {
            if(str[i] < '0' || str[i] > '9') {
                break;
            }

            if (result > INT_MAX) return sign == 1 ? INT_MAX : INT_MIN;
            
            result = result * 10 + (str[i] - '0');
        }

        if (result > INT_MAX) return sign == 1 ? INT_MAX : INT_MIN;
        return result * sign;
    }
};