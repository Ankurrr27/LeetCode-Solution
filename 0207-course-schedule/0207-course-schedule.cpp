class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Adjacency list
        vector<vector<int>> adj(numCourses);

        // Indegree of every course
        vector<int> indegree(numCourses, 0);

        // Build the graph
        for (auto it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];

            // prerequisite -> course
            adj[prerequisite].push_back(course);

            indegree[course]++;
        }

        // Courses that have no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            // Remove this course as a prerequisite
            for (int next : adj[node]) {
                indegree[next]--;

                // All prerequisites completed
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If every course was processed, no cycle exists
        return count == numCourses;
    }
};