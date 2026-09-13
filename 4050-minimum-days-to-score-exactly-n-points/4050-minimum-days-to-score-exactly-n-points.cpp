class Solution {
public:
    int minDays(int n) {
        
        const int INF = 1e9;

        vector<int> dp(n+1,INF);

        dp[0]=0;
        for(int s=0;s<=n;s++){
            if(dp[s]==INF) continue;
            for(int l=1;;l++){
                int p = l*(l+1)/2;
                if(s+p>n) break;
                int extraDays = l;

                if(s>0) extraDays++;

                dp[s+p]=min(dp[s+p],dp[s]+extraDays);
            }
        }
        return dp[n];
    }
};