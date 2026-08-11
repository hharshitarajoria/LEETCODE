class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize != 0) return false;
        sort(hand.begin(),hand.end());
        map<int,int> mpp;
        for(int i=0 ;i<n;i++){
            mpp[hand[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mpp[hand[i]]==0) continue;

            int first= hand[i];

            for(int j=0; j<groupSize;j++){
                if(mpp[first+j]==0) return false;

                mpp[first+j]--;
            }
        }
        return true;
    }
};