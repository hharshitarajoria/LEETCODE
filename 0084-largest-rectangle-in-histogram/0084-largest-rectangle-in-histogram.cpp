class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        stack<int> st;
        int maxArea = 0;
        int area=1;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int ind=st.top();
                st.pop();
                int nse= i;
                int pse;
                if(st.empty()) pse=-1;
                else pse = st.top();
                area= heights[ind]* (nse-pse-1);
                maxArea = max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int ind= st.top();
            st.pop();
            int nse=n;
            int pse;
            if(st.empty()) pse=-1;
            else pse=st.top();
            area= heights[ind] *(nse-pse-1);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};