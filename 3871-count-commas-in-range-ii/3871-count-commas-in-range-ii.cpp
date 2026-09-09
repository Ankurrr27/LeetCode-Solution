class Solution {
public:
    long long countCommas(long long n) {
        long long newn = n;
        long long base = 1000;
        long long ans = 0;

        while(base<=newn){
            ans += newn-base+1;
            base *= 1000;
        }

        return ans;
    }
};