class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        if(s.length() == 1) return s;
        for(int i = 0; i < s.length(); i++){
            int l = i;
            int r = i;
            while(l >= 0 && r <= s.length() - 1 && s[l] == s[r]){   // odd palindrome
                if(r - l + 1 > ans.length()){
                    ans = s.substr(l, r - l + 1);
                }
                l -= 1;
                r += 1;
            }
            l = i;
            r = i + 1;
            while(l >= 0 && r <= s.length() - 1 && s[l] == s[r]){   // even palindrome
                if(r - l + 1 > ans.length()){
                    ans = s.substr(l, r - l + 1);  
                }
                l -= 1;
                r += 1;
            }
        }
        return ans;

    }
};