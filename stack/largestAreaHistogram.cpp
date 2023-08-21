class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int maxArea = 0;

        for (int i=0; i<=heights.size(); i++) {
            int val = 0;
            if (i == heights.size()) val = 0;
            else val = heights[i];

            while (st.top() >= 0 && val <= heights[st.top()]) {
                int nsr = i;
                int h = heights[st.top()];
                st.pop();
                int nsl = st.top();
                int w = nsr - nsl - 1;
                int area = h * w;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        return maxArea;
    }
};