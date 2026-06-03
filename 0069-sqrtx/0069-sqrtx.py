class Solution(object):
    def mySqrt(self, x):

        if x < 2:
            return x
            
        left, right = 0, x
        ans = 0
        
        while left <= right:
            mid = (left + right) // 2
            mid_squared = mid * mid
            
            if mid_squared == x:
                return mid
            elif mid_squared < x:
                ans = mid       
                left = mid + 1  
            else:
                right = mid - 1 
                
        return ans
        