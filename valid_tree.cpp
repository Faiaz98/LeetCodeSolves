class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; //check if the number of edges is correct

        //create an adjacency list
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        //array to keep track of visited nodes
        vector<bool> visited(n, false);

        //stack for DFS
        stack<int>stk;
        stk.push(0); //start dfs from node 0
        visited[0] = true;

        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();

            for (int neighbor : graph[node]) {
                if (visited[neighbor]) continue; //skip already visited nodes

                visited[neighbor] = true;
                stk.push(neighbor);

                //remove the bidirectional link to prevent revisiting the parent node
                graph[neighbor].erase(remove(graph[neighbor].begin(), graph[neighbor].end(), node), graph[neighbor].end());
            } 
        }

        //check if all the nodes are visited

        for (bool v : visited) {
            if (!v) return false; //if any node is not visited, the graph is not connected
        }

        return true; //the graph is a tree (connected and acyclic)
    }
};
