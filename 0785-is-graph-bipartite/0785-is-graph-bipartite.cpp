class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node , int color, vector<int> &colored){
            colored[node]=color;

            for( auto it: graph[node]){
                if(colored[it]==-1){
                    if(dfs(graph,it,!color,colored)==false) return false;
                }
                else if(colored[it]==color) return false;
            }
            return true;
        }
        
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> colored(n,-1);
        for( int i=0;i<n;i++){
            if(colored[i]==-1){
                if(dfs(graph,i,0,colored)== false){
                    return false;
                }
            }
        }
        return true;
    }
};