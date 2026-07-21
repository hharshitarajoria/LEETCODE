class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            int len=0,maxSum=0, sum=0, maxi=INT_MIN;
            for(int j=ind;j < min(n,ind+k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                sum = (len*maxi) + dp[j+1];
                maxSum = max(maxSum, sum);
            }
        dp[ind]= maxSum;
        }
        return dp[0];
    }
};