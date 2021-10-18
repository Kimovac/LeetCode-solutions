class Solution {
public:
    bool containsAllLetters(map<char, int> &hash, string &s1) {
        for(auto c : s1) {
            if(hash[c] != 0)
                return false;
        }
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        map<char, int> hash;
        if(s1.size() > s2.size())
            return false;
        
        for(auto c : s1) {
            if(hash.find(c) != hash.end())
                hash[c]++;
            else
                hash[c] = 1;
        }
        
        int r;
        for(r=0; r<s1.size(); r++) {
            if(hash.find(s2[r]) != hash.end())
                hash[s2[r]]--;
            else
                hash[s2[r]] = 1;
        }
        int l = 0;
        while(r < s2.size()) {
            if(containsAllLetters(hash, s1)) {
                return true;
            }
            else {
                hash[s2[l]]++;
                hash[s2[r]]--;
                l++;
                r++;
            }
        }
        if(containsAllLetters(hash, s1))
            return true;
        
        return false;
    }
};