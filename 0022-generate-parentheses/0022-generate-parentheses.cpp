#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current_string = "";
        
        backtrack(result, current_string, 0, 0, n);
        
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current_string, int open_count, int close_count, int max_pairs) {
        if (current_string.length() == max_pairs * 2) {
            result.push_back(current_string);
            return;
        }

        if (open_count < max_pairs) {
            current_string.push_back('(');
            backtrack(result, current_string, open_count + 1, close_count, max_pairs);
            current_string.pop_back();
        }

        if (close_count < open_count) {
            current_string.push_back(')');
            backtrack(result, current_string, open_count, close_count + 1, max_pairs);
            current_string.pop_back(); 
        }
    }
};