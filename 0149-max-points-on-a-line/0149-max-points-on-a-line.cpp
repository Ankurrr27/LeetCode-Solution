class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1){
            return n; 
        }
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            unordered_map<double, int> freq; 
            for(int j = i+1; j < n; j++){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                double m;
                if (dx == 0) {
                    m = INT_MAX; 
                } else {
                    m = (double)dy / dx; 
                    if (m == -0.0) m = 0.0; 
                }
                freq[m]++;
            }
            for(auto it: freq){
                if(it.second > ans){
                    ans = it.second;
                }
            }
        }
        return ans+1;
    }
};