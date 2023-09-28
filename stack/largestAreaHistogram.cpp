class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        int n = histo.size();
        stack<int> st;
        int maxA = 0;

        for (int i=0; i<=n; i++) {
            while (!st.empty() && (i == n || histo[i] <= histo[st.top()])) {
                int height = histo[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int area = height * width;
                maxA = max(maxA, area);
            }
            st.push(i);
        }

        return maxA;
    }
};

//method-2 (more intuitive)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxA = 0;
        vector<int> ls(n), rs(n);

        for (int i=0; i<n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (st.empty()) ls[i] = 0;
            else ls[i] = st.top()+1;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (st.empty()) rs[i] = n-1;
            else rs[i] = st.top()-1;
            st.push(i);
        }

        for (int i=0; i<n; i++) {
            int h = heights[i];
            int w = rs[i] - ls[i] + 1;
            int area = h * w;
            maxA = max(maxA, area);
        }

        return maxA;
    }
};
