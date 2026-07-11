class Solution {
public:
    bool dfsCheck(int node,  vector<int> &vis, vector<int> &pathvis,vector<int> adj[],vector<int> &ans){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfsCheck(it,vis,pathvis,adj,ans) == true) return true;
            }
            else if( pathvis[it]) return true;
        }
        pathvis[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {

            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }
        vector<int> vis(numCourses,0);
        vector<int> pathvis(numCourses,0);
        vector<int> ans;
        
        for( int i=0;i<numCourses;i++){
            if(!vis[i]){
               if(dfsCheck(i,vis,pathvis,adj,ans)==true){
                  return {};
               }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
