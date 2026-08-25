class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxGreen = *max_element(lights.begin(), lights.end());

        int ans =0;

        for(int i:arrivalTime){
            int j=i%period;

            int wait = 0;
            if(j>=maxGreen){
                wait = period-j;
                
            }
            ans = max(ans,wait);
        }
        return ans;
    }
};