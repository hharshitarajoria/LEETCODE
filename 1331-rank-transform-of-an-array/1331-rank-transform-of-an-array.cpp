class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n= arr.size();
        vector<int> indices(n);
        for(int i=0;i<n;i++){
            indices[i]=i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });
        
        vector<int> ans(n);
        int rank=0;
        int prev = INT_MAX;
        for(int ind=0;ind<n;ind++){
            if(prev!=arr[indices[ind]]){
                prev=arr[indices[ind]];
                rank++;
            }
            ans[indices[ind]]=rank;
        }
        return ans;
    }
};