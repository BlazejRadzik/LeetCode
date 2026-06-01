class Solution(object):
    def strStr(self, haystack, needle):

        H = len(haystack)
        N = len(needle)
        
        for i in range(H - N + 1):
            if haystack[i : i + N] == needle:
                return i
                
        return -1