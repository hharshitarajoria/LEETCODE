class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    pal[i][j] = true;
                }
                else if (j == i + 1) {
                    pal[i][j] = (s[i] == s[j]);
                }
                else {
                    pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
                }
            }
        }
        vector<int> dp(n+1,0);
        for( int i=n-1; i>=0 ; i--){
            string temp="";
            int minCost=INT_MAX;
            for(int j=i;j<n;j++){
                temp += s[j];
            if(pal[i][j]){
                int cost = 1+ dp[j+1];
                minCost = min(minCost,cost);
            }
        }
        dp[i]=minCost;
        }
        return dp[0]-1;
    }
};