//optimized solution
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
};


//more optimized - say only if interviewer asks to optimize above solution more
class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        int n = histo.size();
        stack<int> st;
        int maxA = 0;

        for (int i=0; i<=n; i++){
            while (!st.empty() && (i==n || histo[st.top()] >= histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                maxA = max(maxA, width*height);
            }
            st.push(i);
        }
        return maxA;
    }
};