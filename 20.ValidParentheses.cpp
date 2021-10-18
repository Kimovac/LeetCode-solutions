class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for(auto c : s) {
            if(c == '(' || c == '[' || c == '{')
                open.push(c);
            
            else if(c == ')' || c == ']' || c == '}') {
                if(open.empty())
                    return false;
                
                if(c == ')' && open.top() != '(')
                    return false;
                if(c == ']' && open.top() != '[')
                    return false;
                if(c == '}' && open.top() != '{')
                    return false;
                
                open.pop();
            }
        }
        
        if(!open.empty())
            return false;
        
        return true;
    }
};