class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n= bills.size();
        int five=0, ten=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10){
                if(five==0) return false;
                five--;
                ten++;
            }
            else{ // $20
                //10+5
                if(five>0 && ten>0){
                    ten--;
                    five--;
                }
                //5+5+5
                else if(five>=3){
                    five = five-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};