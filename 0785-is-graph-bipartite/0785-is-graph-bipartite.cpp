class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, -1);
        for (int i = 0; i < n; i++) {
            if (colored[i] != -1)
                continue;
            queue<int> q;
            q.push(i);
            colored[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto it : graph[node]) {
                    if (colored[it] == -1) {
                        colored[it] = !colored[node];
                        q.push(it);
                    }
                    else if (colored[it] == colored[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};