class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        map<char, int> occurances;
        for(auto c : s) {
            if(occurances.find(c) == occurances.end())
                occurances[c] = 1;
            else
                occurances[c]++;
        }
        
        for(auto c : t) {
            if(occurances.find(c) == occurances.end())
                return false;
            else
                occurances[c]--;
        }
        
        for(auto it : occurances) {
            if(it.second != 0)
                return false;
        }
        
        return true;
    }
};