class Solution {
public:
    bool f(vector<int>& bloomDay,int day, int m, int k){
        int cnt=0;
        int noBouqet=0;
        int n= bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                noBouqet += (cnt/k);
                cnt=0;
            }
        }
        noBouqet += (cnt/k);
        if(noBouqet >= m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        if(n< (long long)m*k) return -1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int low= *min_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid= (low+high)/2;
            if(f(bloomDay,mid,m,k)==true){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};