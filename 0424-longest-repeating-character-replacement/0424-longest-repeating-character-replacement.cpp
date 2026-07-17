class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int l,r,maxlen,maxfreq;
        l=r=maxlen=maxfreq=0;
        map<int,int> mpp;
        while(r<n){
            mpp[s[r]-'A']++;
            maxfreq = max(maxfreq, mpp[s[r] - 'A']);
            int len= r-l+1;
            if(len-maxfreq > k){
                mpp[s[l]-'A']--;
                l++;
            }
            else{
                maxlen = max(maxlen,len);
            }
             r++;
        }
       return maxlen;
    }
};