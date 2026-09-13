class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans =0;
        for(auto& [nums,occurance]:mp){
            if(occurance.size() == 3){
               int ind1=occurance[0];
               int ind2=occurance[1];
               int ind3=occurance[2];

                if(ind2-ind1==ind3-ind2){
                    ans++;
                }
                
            }
        }
        return ans;
    }
};