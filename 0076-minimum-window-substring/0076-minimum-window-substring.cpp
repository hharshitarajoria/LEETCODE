class Solution {
public:
    string minWindow(string s, string t) {
        int n= s.size();
        int m= t.size();
        int l=0, r=0, minlen = INT_MAX, cnt=0;
        int sInd=-1;
        map<int,int> mpp;
        for( int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(r<n){
            if(mpp[s[r]] > 0){
                cnt=cnt+1;
            }
                mpp[s[r]]--;
            
            while(cnt == m){
                if((r-l+1)<minlen){
                    minlen = (r-l+1);
                    sInd=l;
                }
                mpp[s[l]]++;
                
                if(mpp[s[l]]>0){ //number added again
                    cnt = cnt-1;
                }
                l++;
            }
            r++;    
        }
        if(sInd==-1) return "";
        return s.substr(sInd, minlen);
    }
};