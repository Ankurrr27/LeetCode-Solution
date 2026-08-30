class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1e9;

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (int x : nums) {
            vector<pair<int, int>> options;
            options.push_back({x, 0});
            long long val = x;
            int cost = 0;
            while (val * 2 <= sum) {
                val *= 2;
                cost++;
                options.push_back({(int)val,cost});
            }
            val=x;
            cost=0;
            while(val>0){
                val/=2;
                cost++;
                if(val>0) options.push_back({(int)val,cost});
            }
            vector<int> ndp=dp;
            for(int s=0;s<=sum;s++){
                if(dp[s]==INF)continue;
                for(auto[value,operations]:options){
                    if(s+value<=sum){
                        ndp[s+value]=min(ndp[s+value],dp[s]+operations);
                    }
                }
            }
            dp=ndp;
        }
        return dp[sum] == INF?-1:dp[sum];
    }
};