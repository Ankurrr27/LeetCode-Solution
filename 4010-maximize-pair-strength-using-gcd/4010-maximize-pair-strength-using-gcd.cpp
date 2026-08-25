class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        // vector<int> nums1 = nums.sort();
        int n = nums.size();
        long long ans =0;
        

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                long long g= gcd(nums[i],nums[j]);
                long long strength = (1LL*nums[i]*nums[j])/(g*g);
                ans = max(ans,strength);
            }
        }
        return ans;
        
    }
};