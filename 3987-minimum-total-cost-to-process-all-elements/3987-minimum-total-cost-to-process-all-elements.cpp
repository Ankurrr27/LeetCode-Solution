class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        long long cur = k;
        long long ops = 0;
        long long ans = 0;

        for(int x:nums){
            if(cur<x){
                long long weneed = x-cur;
                long long t = (weneed+k-1)/k;


                // long long cost = t*(2*ops+t+1)/2;
                // __int128 cost = (__inst128)t*(2*(__int128)ops+t+1)/2;

                // ans = (ans+(long long)(cost%MOD))%MOD;

                const long long I2 = 500000004;

                long long a = t%MOD;
                long long b = ((2*(ops%MOD))%MOD+a+1)%MOD;

                long long cost = (a*b)%MOD;
                cost = (cost *I2)%MOD;

                ans = (ans +cost)%MOD;

                ops+=t;
                cur+=t*1LL*k;
            }
            cur -= x;
        }
        return ans %MOD;
    }
};