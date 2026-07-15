class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int r=0;
        int l=0;
        int maxlen=0;
        vector<int> hash(256,-1);
        while(r<n){
            if(hash[s[r]]!=-1){
                if(l<= hash[s[r]]){
                    l = hash[s[r]]+1;
                }
            }
            int len= r-l+1;
            maxlen= max(len,maxlen);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};