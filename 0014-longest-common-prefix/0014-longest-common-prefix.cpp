#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        
        std::sort(strs.begin(), strs.end());
        
        std::string first = strs.front();
        std::string last = strs.back();
        std::string result = "";
        
        for (int i = 0; i < std::min(first.length(), last.length()); i++) {
            if (first[i] == last[i]) {
                result += first[i];
            } else {
                break;
            }
        }
        
        return result;
    }
};