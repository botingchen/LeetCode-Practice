class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start < end){
            if(!(isalpha(s[start])||isdigit(s[start])) || isspace(s[start])) start++;
            else if(!(isalpha(s[end])||isdigit(s[end])) || isspace(s[end])) end--;
            else if(!(tolower(s[start]) == tolower(s[end]))){
                cout<<s[start]<<s[end]<<endl;
                return false;
            }
           else{
               start++;
               end--;
           }
        }
        return true;
    }
};