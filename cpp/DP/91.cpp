class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        if(s.length() == 1){
            if(s[0] - '0' > 0) return 1;
            else return 0;
        }
        vector<int> dp(s.length(), 0);
        dp[0] = 1;
        if(s[1] - '0' > 0) dp[1] += 1;
        if(std::stoi(s.substr(0,2)) >= 10 && std::stoi(s.substr(0,2)) <= 26) dp[1] += 1;
        for (int i = 2; i < s.length(); ++i) {
            if (s[i] - '0' > 0) {
                dp[i] += dp[i - 1];
            }

            if (10 <= std::stoi(s.substr(i - 1, 2)) && std::stoi(s.substr(i - 1, 2)) <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.length()-1];
    }
};