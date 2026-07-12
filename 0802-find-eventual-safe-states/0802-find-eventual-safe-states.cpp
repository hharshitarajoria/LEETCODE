class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int> graphRev[V];
        vector<int> inDegree(V,0);
        queue<int> q;
        //reverse
        for( int i=0;i<V;i++){
            // i->it convert to it->i
            for( auto it: graph[i]){
                graphRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        for( int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safeStates;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            safeStates.push_back(node);
            for( auto it: graphRev[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safeStates.begin(),safeStates.end());
        return safeStates;
    }
};