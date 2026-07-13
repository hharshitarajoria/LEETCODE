class Solution {
public:
    bool CanCompleteCourse(int V, vector<int> adjprerequisites[], vector<int> &inDegree,queue<int> &q){
        int count=0;
        for(int i=0;i<V ;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            count++;
            for( auto it : adjprerequisites[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count==V) return true;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V= numCourses;
        queue<int> q;
        vector<int> inDegree(V,0);

        vector<int> adjprerequisites[V];
            for(auto it:prerequisites){
                int a= it[0];
                int b= it[1];
                adjprerequisites[b].push_back(a);
            }

        for( int i=0;i<V;i++){
            for(auto it:adjprerequisites[i]){
                inDegree[it]++;
            }
        }
        if(CanCompleteCourse(V,adjprerequisites,inDegree,q)==true) return true;

        return false; 
    }
};