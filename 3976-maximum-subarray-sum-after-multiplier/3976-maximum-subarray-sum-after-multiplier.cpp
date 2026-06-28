class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        auto solve = [&](bool mul) {
            auto convert = [&](int x) -> long long {
                if (mul)
                    return 1LL * x * k;
                if (x >= 0)
                    return x / k;
                return -((-x) / k);
            };

            const long long NEG = -(1LL << 60);

            long long dp0 = NEG;
            long long dp1 = NEG;
            long long dp2 = NEG;
            long long ans = NEG;

            for (int x : nums) {
                long long y = convert(x);
                long long ndp0 = max(dp0 + x, 1LL * x);

                long long ndp1 = max({y, dp0 + y, dp1 + y});

                long long ndp2 = max({ dp1 + x, dp2 + x});

                dp0=ndp0;
                dp1=ndp1;
                dp2=ndp2;

                ans = max({ans, dp0, dp1, dp2});
            }

            return ans;
        };

        return max(solve(true),solve(false));
    }
};