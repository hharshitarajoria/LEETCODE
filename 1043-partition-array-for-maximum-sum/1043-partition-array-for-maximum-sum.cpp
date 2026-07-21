class Solution {
public:
    int f(int ind, int n, vector<int> &ans,int k, vector<int> &dp){
        if(ind==n)return 0;
        int len=0,maxSum=0, sum=0, maxi=INT_MIN;
        if(dp[ind]!= -1) return dp[ind];
        for(int j=ind;j < min(n,ind+k); j++){
            len++;
            maxi = max(maxi, ans[j]);
            sum = (len*maxi) + f(j+1,n,ans,k,dp);
            maxSum = max(maxSum, sum);
        }
        return dp[ind]= maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,n,arr,k,dp);
    }
};