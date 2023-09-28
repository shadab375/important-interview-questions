class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;

        int water = 0;

        for (int i=0; i<n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int index = st.top();
                st.pop();

                if (st.empty()) break;

                int h = min(height[i], height[st.top()]) - height[index];
                int w = i-st.top()-1;

                water += h*w;
            }
            st.push(i);
        }

        return water;
    } 
};