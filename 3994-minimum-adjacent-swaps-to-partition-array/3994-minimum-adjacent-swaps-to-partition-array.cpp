class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long M = 0;
        long long H = 0;
        long long ans = 0;
        const int MOD = 1e9+7;

        for(int i:nums){
            if(i<a){
                ans+=M+H;
            }
            else if(i<=b){
                ans+=H;
                M++;
            } else {
                H++;
            }
        }
        return ans % MOD;
    }
};
