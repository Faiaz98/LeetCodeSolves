class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build the graph
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int coursesTaken = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesTaken++;

            for (int neighbor : graph[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return coursesTaken == numCourses;
    }
};
