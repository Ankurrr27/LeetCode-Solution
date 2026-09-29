#define ll long long 

class Solution {
private:

bool valid(ll mid,vector<ll>&arr,vector<int>&mons){

    //we have to perform 
    int n=mons.size();
    ll prev=mid;
    for(int i=0;i<n;i++){

        ll total=prev+arr[i];
        if(total>=mons[i]){
            prev=max(0LL,prev-mons[i]);
        }
        else return false;
        //prev=curr;
    }


    return true;
}
public:
    ll minInitialStrength(vector<int>& mons, vector<vector<int>>& boo) {
        //just simple diff array +binary search on ans

        int n=mons.size();
        vector<ll>arr(n+1,0);
       // arr.push_back(0);
        for(auto i:boo){
            int st=i[0],en=i[1],val=i[2];

            arr[st]+=val;
            arr[en+1]-=val;


        }


        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }

        ll start=0,end=accumulate(mons.begin(),mons.end(),0LL);
        ll ans=end;

        while(start<=end){
            ll mid=start+(end-start)/2;

            if(valid(mid,arr,mons)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;


        }

        return ans;



        
    }
};