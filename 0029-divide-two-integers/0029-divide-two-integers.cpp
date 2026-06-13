class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }
        
        int quotient = 0;
        int HALF_MIN = -1073741824; 
        
        while (dividend <= divisor) {
            int powerOfTwo = -1;
            int value = divisor;
            
            while (value >= HALF_MIN && dividend <= value + value) {
                value += value;
                powerOfTwo += powerOfTwo;
            }
        
            dividend -= value;
            quotient += powerOfTwo;
        }
        
        return negatives == 1 ? quotient : -quotient;
    }
};