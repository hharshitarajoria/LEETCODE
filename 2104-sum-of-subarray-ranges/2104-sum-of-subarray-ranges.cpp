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
    vector<int> findNGE(vector<int>& arr){
        int n= arr.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1; i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = n;
            else nge[i]= st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findPGE(vector<int>& arr){
        int n= arr.size();
        vector<int> pge(n);
        stack<int> st;
        for(int i=0; i<n ;i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(st.empty()) pge[i] = -1;
            else pge[i]=st.top();
            st.push(i);
        }
        return pge;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int> pse= findPSE(arr);
        vector<int> nse= findNSE(arr);
        int MOD= 1e9+7;
        long long sum=0;
        for(int i=0;i<n;i++){
            long long left = i-pse[i];
            long long right = nse[i]-i;
            sum = (sum+ (left*right*1LL*arr[i]));
        }
        return sum;
    }
   long long sumSubarrayMaxs(vector<int>& arr) {
        int n= arr.size();
        vector<int> pge= findPGE(arr);
        vector<int> nge= findNGE(arr);
        long long sum=0;
        for(int i=0;i<n;i++){
            long long left = i-pge[i];
            long long right = nge[i]-i;
            sum = (sum+ (left*right*1LL*arr[i]));
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};