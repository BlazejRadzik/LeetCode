class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map_s(256, -1);
        vector<int> map_t(256, -1);
        
        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];
            
            if (map_s[c1] == -1 && map_t[c2] == -1) {
                map_s[c1] = c2;
                map_t[c2] = c1;
            } 
            else if (map_s[c1] != c2 || map_t[c2] != c1) {
                return false;
            }
        }
        
        return true;
    }
};