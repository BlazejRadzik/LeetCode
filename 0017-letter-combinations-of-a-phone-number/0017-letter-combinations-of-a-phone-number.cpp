#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        vector<string> pad = {
            "", "", "abc", "def", "ghi", "jkl", 
            "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        string currentCombo = "";
        
        backtrack(digits, 0, currentCombo, result, pad);
        
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& currentCombo, vector<string>& result, const vector<string>& pad) {
        if (index == digits.length()) {
            result.push_back(currentCombo);
            return;
        }
        
        int digit = digits[index] - '0'; 
        string letters = pad[digit];
        
        for (char letter : letters) {
            currentCombo.push_back(letter);                      
            backtrack(digits, index + 1, currentCombo, result, pad); 
            currentCombo.pop_back();                              
        }
    }
};