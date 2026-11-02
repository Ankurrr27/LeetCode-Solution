class Solution {
public:
    vector<int> tin, low;
    vector<vector<int>> adj;
    vector<vector<int>> bridges;
    int timer= 0;

    void dfs(int node, int parent){
        tin[node] = low[node] = timer++;

        for(int neigh: adj[node]){
            if(neigh == parent) continue;
            if(tin[neigh]!=-1){
                low[node]=min(low[node], tin[neigh]);
            } else {
                dfs(neigh, node);
                low[node]=min(low[node], low[neigh]);

                if(low[neigh]>tin[node]){
                    bridges.push_back({node, neigh});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections
    ) {
        adj.resize(n);

        for (auto &edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        tin.assign(n, -1);
        low.assign(n, -1);

        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) {
                dfs(i, -1);
            }
        }

        return bridges;
    }
};