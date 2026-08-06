class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        int n= arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1; i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else nse[i]= st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int>& arr){
        int n= arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0; i<n ;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int> pse= findPSE(arr);
        vector<int> nse= findNSE(arr);
        int MOD= 1e9+7;
        int sum=0;
        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            sum = (sum+ (left*right*1LL*arr[i])%MOD)%MOD;
        }
        return sum;
    }
};