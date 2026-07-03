class Solution {
public:
    vector<string> getTokens(string &v){
        stringstream ss(v);
        string token=""; //aal tokens of string in this
        vector<string> tokens; // the tokens that came from above will be added here
        while(getline (ss,token,'.')){
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);

        int m=v1.size();
        int n=v2.size();
        int i=0;

        while(i<m || i<n){
            int a= i<m? stoi(v1[i]):0;
            int b= i<n? stoi(v2[i]):0; // ?true cond:false cond

            if(a<b) return -1;
            else if(a>b) return 1;
            else i++;
        }
        return 0; // equal versions;   
    }
};