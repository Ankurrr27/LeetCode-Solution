class Solution {
public:
    // T: O(M*N). bfs + dp: maxHealth from [0,0] to [i,j]
bool findSafeWalk(vector<vector<int>>& g, int health) {
    int m = g.size(), n = g[0].size(), dir[5] = {0,1,0,-1,0};
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = health-g[0][0]; // base case
    queue<int> q{{0}};
    while(!q.empty()){
        int i = q.front()/n, j = q.front()%n; q.pop();
        if(dp[m-1][n-1]>0) return true; // early termination
        for(int k=0; k<4; ++k){
            int x = i+dir[k], y = j+dir[k+1];
            if(min(x,y)<0 || x>=m || y>=n || dp[x][y]>= dp[i][j]-g[x][y]) continue;
            dp[x][y] = dp[i][j]-g[x][y]; // update maxHealth
            q.push(x*n+y);
        }
    }
    return false; // return dp[m-1][n-1]>0; // replace, if no/comment early termination
}
};