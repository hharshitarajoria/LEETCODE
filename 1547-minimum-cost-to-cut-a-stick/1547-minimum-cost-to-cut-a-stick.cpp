class Solution {
public:
    int f(int i, int j, vector<int> &cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        // cuts[j+1]=n;
        // cuts[i-1]=0;
        int mini=1e9; // max possible value
        if(dp[i][j] != -1) return dp[i][j];
        for( int ind=i; ind<=j ;ind++){
            int cost= cuts[j+1]-cuts[i-1] + f(i, ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int c= cuts.size();
        vector<vector<int>> dp(c, vector<int>(c,-1));
        // return f(1,c-1,cuts);    wrong as we added n in the end
        return f(1,c-2,cuts,dp);
    }
};