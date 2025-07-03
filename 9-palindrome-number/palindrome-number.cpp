class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long reverse = 0;
        long original = x;

        while(x != 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }

        return reverse == original;
    }
};