class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t size = s.size();
        for(int i = 0; i < size / 2; i++){
            char tmp = s[i];
            s[i] = s[size - i - 1];
            s[size - i - 1] = tmp;
        }
    }
};