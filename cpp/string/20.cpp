class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(char c : s){
            if(c == '(') mystack.push(')');
            else if(c == '[') mystack.push(']');
            else if(c == '{') mystack.push('}');
            else if(mystack.empty() || mystack.top() != c) return false;
            else if (mystack.top() == c) mystack.pop();

        }
        if(!mystack.empty()) return false;
        return true;
    }
};