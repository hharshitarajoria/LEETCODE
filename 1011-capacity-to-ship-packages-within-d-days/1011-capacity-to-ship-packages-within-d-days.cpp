class Solution {
public:
    int f(vector<int>& weights, int capacity){
        int load=0, day=1;
        for(int i=0; i<weights.size(); i++){
            if(load+weights[i] > capacity){
                day= day+1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int mini = *max_element(weights.begin(), weights.end());
        int sum=0;
        for(int i=0;i<n;i++){
            sum += weights[i];
        }
        int low=mini, high=sum;
        while(low<=high){
            int mid= (low+high)/2;
            int daysReq = f(weights,mid);
            if(daysReq <= days) high=mid-1;
            else low=mid+1;
    }
        return low;
    }
};