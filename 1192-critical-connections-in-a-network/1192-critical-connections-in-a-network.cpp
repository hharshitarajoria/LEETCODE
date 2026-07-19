class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<int> &vis,
                        vector<int> adj[],int low[],int tin[],vector<vector<int>> &bridges){
        vis[node]=1;
        low[node]=tin[node]= timer;
        timer++;
        for(auto it: adj[node]){
            if(it==parent) continue; // dont include parent
            if(vis[it]==0){
                dfs(it,node,vis,adj,low,tin,bridges);
                low[node]= min(low[node],low[it]);
                //node --- it
                if(low[it] > tin[node]) // it is a bridge
                {
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]= min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for( auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,low,tin,bridges);
        return bridges;
    }
};