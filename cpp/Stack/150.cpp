class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        int ans = 0;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = mystack.top();
                mystack.pop();
                int b = mystack.top();
                mystack.pop();
                if(tokens[i] == "+") mystack.push(a+b);
                else if(tokens[i] == "-") mystack.push(b-a);
                else if(tokens[i] == "*") mystack.push(a*b);
                else if(tokens[i] == "/") mystack.push(b/a);
            }
            else{
                mystack.push(stoi(tokens[i]));
            }
            // cout << mystack.top() << endl;
        }
        return mystack.top();
    }
};