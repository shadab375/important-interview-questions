class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int leftSmaller[n], rightSmaller[n];

        //filling left Smaller
        for (int i=0; i<n; i++){
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (st.empty()) leftSmaller[i] = 0;
            else leftSmaller[i] = st.top() + 1;
            st.push(i);
        }

        //to reuse the stack, reset it
        while (!st.empty()) st.pop();

        //filling rightSmaller
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (st.empty()) rightSmaller[i] = n-1;
            else rightSmaller[i] = st.top() - 1;
            st.push(i);
        }

        int maxArea = 0;
        for (int i=0; i<n; i++){
            maxArea = max(maxArea, heights[i] * (rightSmaller[i] - leftSmaller[i] + 1));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;
        vector<int> height(m, 0);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};