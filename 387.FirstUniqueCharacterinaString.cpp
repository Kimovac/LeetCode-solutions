class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> occurances;
        for(auto c : s) {
            if(occurances.find(c) == occurances.end())
                occurances[c] = 1;
            else
                occurances[c]++;
        }
        for(int i=0; i<s.size(); i++) {
            if(occurances[s[i]] == 1)
                return i;
        }
        
        
        return -1;
    }
};