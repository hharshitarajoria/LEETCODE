class Solution {
public:
    string removeKdigits(string num, int k) {
        int n= num.size();
        stack<char> st;
        if(k==n) return "0";
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k--) st.pop();

        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
                st.pop();
        }
        reverse(ans.begin(), ans.end());

        int pos = ans.find_first_not_of('0');
        if(pos == string::npos)
            return "0";
        return ans.substr(pos);

        return ans;
    }
};