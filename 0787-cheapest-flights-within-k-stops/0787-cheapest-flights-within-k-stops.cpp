class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for( auto it: flights){
            int a= it[0];
            int b= it[1];
            int weight= it[2];
            adj[a].push_back({b,weight});
        }
        queue<pair<int,pair<int,int>>> q; // ({stops,{node,dist}})
        vector<int> dist(n+1,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stop= q.front().first;
            int node= q.front().second.first;
            int price= q.front().second.second;
            q.pop();

            if(stop>k) break;

            for(auto it: adj[node]){
                int adjNode= it.first;
                int edgeWT= it.second;
                if(price+edgeWT < dist[adjNode]){
                    dist[adjNode] = price + edgeWT;
                    q.push({stop+1,{adjNode,price + edgeWT}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};