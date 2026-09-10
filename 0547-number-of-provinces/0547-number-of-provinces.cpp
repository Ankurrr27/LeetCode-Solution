class Solution {
private:

    // DFS to visit all the nodes belonging to the same province
    void dfs(int node, vector<vector<int>>& adjV, vector<int>& visited) {

        // Mark the current node as visited
        visited[node] = 1;

        // Visit all the neighbours of the current node
        for(int neighbor : adjV[node]) {

            // If the neighbour has not been visited yet
            if(visited[neighbor] == 0) {

                // Recursively visit that neighbour
                dfs(neighbor, adjV, visited);
            }
        }
    }

public:

    int findCircleNum(vector<vector<int>>& isConnected) {

        // Number of cities/nodes
        int n = isConnected.size();

        // Adjacency list
        // adjV[i] stores all the cities directly connected to city i
        vector<vector<int>> adjV(n);

        // Convert adjacency matrix into adjacency list
        for(int i = 0; i < n; i++) {

            // Start from i + 1 to avoid adding the same edge twice
            for(int j = i + 1; j < n; j++) {

                // If city i and city j are directly connected
                if(isConnected[i][j] == 1) {

                    // Add j as a neighbour of i
                    adjV[i].push_back(j);

                    // Since the graph is undirected,
                    // add i as a neighbour of j
                    adjV[j].push_back(i);
                }
            }
        }

        // visited[i] = 1 means city i has already been visited
        vector<int> visited(n, 0);

        // Number of provinces
        int cnt = 0;

        // Check every city
        for(int i = 0; i < n; i++) {

            // If this city has not been visited,
            // it means we found a new province
            if(visited[i] == 0) {

                // Visit the complete connected component
                dfs(i, adjV, visited);

                // One DFS = one complete province
                cnt++;
            }
        }

        // Return total number of provinces
        return cnt;
    }
};