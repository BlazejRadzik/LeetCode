class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        INT_MAX = 2**31 - 1
        
        res = 0
        is_negative = x < 0
        x = abs(x)
        
        while x != 0:
            pop = x % 10
            x //= 10
            if res > (INT_MAX - pop) // 10:
                return 0
            
            res = (res * 10) + pop
            
        return -res if is_negative else res