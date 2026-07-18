class DisjointSet{
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1);
        for( int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
        rank.resize(n+1,0);
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node]= findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]< rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]< size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        unordered_map<string,int> mapMailNode;
        //connecting nodes, making disjoint set, making ultimate parents
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email= accounts[i][j];
                if( mapMailNode.find(email)== mapMailNode.end()){
                     mapMailNode[email]=i;
                }
                else{
                    ds.unionBySize(i, mapMailNode[email]);
                }
            }
        }
        //merging according to disjoint data structure
        vector<string> mergedMail[n];
        for( auto it:  mapMailNode){
            string mail= it.first;
            int node= ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        //rearranging to output merged with the name as list of list
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if( mergedMail[i].size()==0) continue; // nodes with no mail
            sort(mergedMail[i].begin(),mergedMail[i].end() ); // for each node individual sorting
            //[name, sorted mails]:
            vector<string> temp;
            temp.push_back(accounts[i][0]); // 0th indexes are names
            for( auto it: mergedMail[i]){
                temp.push_back(it); //put sorted mails for each name
            }
            ans.push_back(temp);
        }
        return ans;
    }
};