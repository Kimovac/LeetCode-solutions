class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> hash;  
        int max_len = s.size() > 0 ? 1 : 0;
        
        int begin = 0;
        for(int end=0; end<s.size(); end++) {
            if(hash.find(s[end]) != hash.end()) {
                begin = max(begin, hash[s[end]]+1);
            }
            
            hash[s[end]] = end;
            max_len = max(max_len, end-begin+1);
        }
        
        return max_len;
    }
};