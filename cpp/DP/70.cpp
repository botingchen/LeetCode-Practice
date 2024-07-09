class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int myarr[n];
        myarr[0] = 1;
        myarr[1] = 2;
        for(int i = 2; i < n; i++){
            myarr[i] = myarr[i - 1] + myarr[i - 2];
        }
        return myarr[n-1];

    }
};