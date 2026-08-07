class Solution {
public:
    vector<int> findNSE(vector<int>& heights){
        int n= heights.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>= heights[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else nse[i]= st.top();

            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int>& heights){
        vector<int> pse(heights.size());
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]> heights[i]){
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else pse[i]= st.top();

            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int maxArea = INT_MIN;
        vector<int> pse= findPSE(heights);
        vector<int> nse= findNSE(heights);
        for(int i=0;i<n;i++){
            int height = heights[i];
            int width = (nse[i]-pse[i])-1;
            int area = height*width;
             maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};