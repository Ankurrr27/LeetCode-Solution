class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map <int,vector<int>> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans =0;
        
        for(auto& [value,occur] : mp){
            if(occur.size()>=3){
                int diff = occur[1]-occur[0];
                bool special = true;
                for(int i=2;i<occur.size();i++){
                    if(occur[i]-occur[i-1]!=diff){
                        special = false;
                        break;
                    }
                }
                if(special) ans++;
               
            }
        }
        return ans;
    }
};