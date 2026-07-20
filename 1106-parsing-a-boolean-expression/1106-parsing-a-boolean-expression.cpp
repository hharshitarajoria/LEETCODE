class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for( auto ch : expression){
            if(ch==',') continue;
            // if( ch == '(' || ch == '&'  || ch == '!' 
            //     || ch == '|' || ch == 't'  ch == 'f'){
            if(ch!=')'){
                st.push(ch);
            }
            // if(ch == ')')
            else {
                int truecount=0;
                int falsecount=0;
                while(!st.empty() && st.top() != '('){
                    if(st.top()=='t'){
                         truecount++;
                    }
                    else if( st.top()=='f'){
                         falsecount++;
                    }
                    st.pop();
                }
                st.pop(); //remove (

                char op= st.top();
                st.pop();

                char result;

                if(op=='&'){
                    if(falsecount==0) result='t';
                    else result='f';
                }
                else if(op=='!'){
                    if(truecount==1) result='f';
                    else result='t';
                }
                else{ // or 
                    if(truecount==0) result='f';
                    else result='t';
                }
                st.push(result);
            }
        }
        return st.top()=='t';
    }
};