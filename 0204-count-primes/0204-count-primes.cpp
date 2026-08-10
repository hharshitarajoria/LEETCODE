class Solution {
public: 
    int countPrimes(int n) {
        vector<int> prime(n+1,1);
        int cnt=0;
        for(int i=2;i<n;i++){
            if(prime[i]==1) cnt++;
            for(int j = 2*i ; j<=n ;j+=i){
                prime[j]=0;
            }
        }
        return cnt;
    }
};