class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1e9;

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (int x : nums) {
            vector<pair<int, int>> options;
            int value = x;
            int divCost = 0;

            while (value > 0) {
                long long cur = value;
                int mulCost = 0;
                while (value > 0) {
                    long long cur = value;
                    int mulCost = 0;
                    while (cur <= sum) {
                        options.push_back({(int)cur, divCost + mulCost});
                        cur *= 2;
                        mulCost++;
                    }
                    value /= 2;
                    divCost++;
                }
                vector<int> ndp = dp;
                for (int oldSum = 0; oldSum <= sum; oldSum++) {
                    if (dp[oldSum] == INF)
                        continue;

                    for (auto [value, cost] : options) {
                        if (oldSum + value <= sum) {
                            ndp[oldSum + value] =
                                min(ndp[oldSum + value], dp[oldSum] + cost);
                        }
                    }
                }
                dp = ndp;
            }
            
        }
        return dp[sum] == INF ? -1 : dp[sum];
    }
};