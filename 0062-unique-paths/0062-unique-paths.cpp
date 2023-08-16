class Solution {
public:
    int wrapperFunc(vector<vector<int>> &dp, int m, int n){
        if(m == 0 && n == 0)
            return 1;

        if(m < 0 || n < 0)
            return 0;

        if(dp[m][n] == -1){
            int r;

            r = wrapperFunc(dp,m-1,n) + wrapperFunc(dp,m,n-1);
            dp[m][n] = r;
        }

        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return wrapperFunc(dp, m-1 ,n-1);
    }
};