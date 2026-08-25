class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int minDist = INT_MAX;

        int tx = target[0];
        int ty = target[1];

        int n = drones.size();
        for(int i=0;i<n;i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];

            int dist = abs(x-tx)+abs(y-ty);

            if(dist<=range && dist<minDist){
                minDist = dist;
                ans = i;
                
            }
            
        }
        return ans;
    }
};