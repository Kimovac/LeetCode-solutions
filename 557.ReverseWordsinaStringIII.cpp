class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int r;
        for(int i=0; i<=s.size(); i++) {
            if(i == s.size() || s[i] == ' ') {
                r = i-1;
                while(l < r) {
                    swap(s[l], s[r]);
                    l++;
                    r--;
                }
                if(s[i] == ' ')
                    l = i+1;
                else
                    l = i;
            }
        }
        
        return s;
    }
};