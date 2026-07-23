class Solution {
public:
    int func(string&s, string&t, vector<vector<int>>&dp, int n, int m, vector<vector<int>>&memo){
        if(m==0) return 1;
        if(n==0) return 0;
        if(memo[n][m]!=-1) return memo[n][m];
        int ans = 0;
        if(s[n-1]==t[m-1]){
            ans=func(s,t,dp,n-1,m-1, memo);
            if(dp[n-1][m]==dp[n][m]) ans+=func(s,t,dp,n-1,m, memo);
        }else{
            if(dp[n-1][m]==dp[n][m]) ans=func(s,t,dp,n-1,m, memo);
        }
        return memo[n][m] =  ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int row=1; row<=n; row++){
            for(int col =1; col<=m; col++){
                if(s[row-1]==t[col-1]) dp[row][col] = 1+dp[row-1][col-1];
                else dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
            }
        }
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        return func(s,t,dp,n,m, memo);
        
    }
};