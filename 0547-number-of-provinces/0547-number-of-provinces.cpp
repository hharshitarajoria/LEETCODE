class Solution {
public:
    void dfs(int node,vector<vector<int>> &adjLS, vector<int> &vis){
        vis[node]=1;
        for( auto it: adjLS[node]){
            if(!vis[it]){
                dfs(it, adjLS,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // adjacency matrix -> adjacency list
        int V = isConnected.size();
       vector<vector<int>> adjLS(V);

        for( int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }
        vector<int> vis(V, 0);
        int count=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i, adjLS,vis);
            }
        } 
        return count; 
    }
};