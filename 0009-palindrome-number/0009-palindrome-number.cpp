class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x !=0)){
            return false;
        } 

        int revhalf = 0;
        while (x > revhalf) {
            int lastdigit = x % 10;
            revhalf = revhalf* 10 + lastdigit;
            x /= 10;
        }

        return x == revhalf || x == revhalf / 10;
    }
};
