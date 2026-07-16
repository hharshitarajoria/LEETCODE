class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for( auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>> pq;
        vector<long long> time(n,1e18);
        time[0]=0;
        pq.push({0,0});
        vector<int> ways(n,0);
        ways[0]=1;

        int mod = (int) (1e9+7);
        while(!pq.empty()){
            int node= pq.top().second;
            long long t= pq.top().first;
            pq.pop();
            for( auto it: adj[node]){
                int adjNode= it.first;
                int edgeTime= it.second;
                // 1st time arriving at node
                if( t + edgeTime < time[adjNode]){
                    time[adjNode] = t+ edgeTime;
                    pq.push({time[adjNode], adjNode});
                    ways[adjNode] = ways[node]; 
                }
                else if( t+ edgeTime == time[adjNode]){
                    ways[adjNode] = (ways[node] +ways[adjNode])  % mod;
                }
            }
        }
        return (ways[n-1] % mod);
    }
};