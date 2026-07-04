class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node,
             vector<vector<pair<int,int>>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for (auto &[nei, dist] : adj[node]) {

            ans = min(ans, dist);

            if (!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int d = r[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<int> vis(n + 1, 0);

        dfs(1, adj, vis);

        return ans;
    }
};