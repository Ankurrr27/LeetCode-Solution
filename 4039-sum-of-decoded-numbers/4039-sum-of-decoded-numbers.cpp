class Solution {
public:
    long long MOD= 1e9+7;

    long long power(long long x, long long y){
        long long ans =1;
        while(y>0){
            if(y&1){
                ans=(ans*x)%MOD;
            }
            x=(x*x)%MOD;
            y>>=1;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long total = 0;
        for(long long num:nums){
            int width = num%10;
            long long d = num/10;
            long long temp=d;
            int digits=0;
            while(temp>0){
                digits++;
                temp/=10;
            }
            long long p=1;
            for(int i=0;i<digits-width;i++){
                p*=10;
            }
            long long x = d/p;
            long long y=d%p;
            total = (total+power(x,y))%MOD;
        }
        return total;
        
    }
};