class Solution {
public:
    bool isUgly(int n) {
        // Ugly numbers must be positive
        if (n <= 0) return false;
        
        // Divide by 2, 3, and 5
        int factors[] = {2, 3, 5};
        for (int f : factors) {
            while (n % f == 0) {
                n /= f;
            }
        }
        
        // If the remaining value is 1, it's an ugly number
        return n == 1;
    }
};