class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        int num=1;
        while(true){
            bool found= false;
            for(int i=0;i<n;i++){
                if(arr[i]==num){
                    found=true;
                    break;
                }
            }
            if(!found){
                k--;
                if(k==0) return num;
            }
            num++;
        }
     return -1;
    }
};