class Solution {
public:
    vector<int> topologicalSortCheck(unordered_map<int, vector<int>>& adj, int n, vector<int>& outdegree) {
        queue<int> que;
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (outdegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();
            result.push_back(u);

            for (int v : adj[u]) {
                outdegree[v]--;
                if (outdegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> adj;
        vector<int> outdegree(n, 0);

        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                adj[v].push_back(u);
                outdegree[u]++;
            }
        }

        return topologicalSortCheck(adj, n, outdegree);
    }
};