class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())
            return false;
        
        map<int, int> occurances;
        for(auto c : ransomNote) {
            if(occurances.find(c) == occurances.end())
                occurances[c] = 1;
            else
                occurances[c]++;
        }
        
        for(auto c : magazine) {
            if(occurances.find(c) == occurances.end())
                continue;
            else
                occurances[c]--;
        }
        
        for(auto it : occurances) {
            if(it.second > 0)
                return false;
        }
            
        return true;
    }
};