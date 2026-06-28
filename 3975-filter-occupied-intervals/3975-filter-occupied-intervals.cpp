class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> ans;

        int l = occupiedIntervals[0][0];
        int r = occupiedIntervals[0][1];

        auto process = [&](int L, int R){
            if(R<freeStart || L>freeEnd){
                ans.push_back({L,R});
            } else {
                if(L<freeStart){
                    ans.push_back({L, freeStart-1});
                } if(R>freeEnd){
                    ans.push_back({freeEnd+1,R});
                }
            }
        };

        for(int i=1;i<occupiedIntervals.size();i++){
            if(occupiedIntervals[i][0]<=r+1){
                r=max(r,occupiedIntervals[i][1]);
            } else {
                process(l,r);
                l=occupiedIntervals[i][0];
                r=occupiedIntervals[i][1];
            }
        }
        process(l,r);
        return ans;
    }
};