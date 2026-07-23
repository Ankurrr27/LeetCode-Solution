class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        // long long ans1 = s;
        // long long ans2 = s;

        // long long curr = s;
        // ans1=curr;

        // for(int i=1;i<n;i++){
        //     if(i&1) curr-=1;
        //     else curr+=m;
        //     ans1=max(ans1,curr);
        // }

        // curr=s;
        // ans2=curr;

        // for(int i=1;i<n;i++){
        //     if(i&1) curr+=m;
        //     else curr-=1;
        //     ans2=max(ans2,curr);
        // }

        // return max(ans1,ans2);

        long long ans = s;

        long long u1 = n/2;
        if(u1>0)
            ans = max(ans,1LL*s+u1*m-(u1-1));

        long long u2 = (n-1)/2;
        if(u2>0)ans = max(ans,1LL*s+u2*m-u2);

        return ans;
    }
};