//SPACE COMPLEXITY - O(1), TIME COMPLEXITY - O(N)
class Solution {
public:
    vector<int> getLeftMaxArray(vector<int>& height, int& n) {
        vector<int> leftMax(n);

        leftMax[0] = height[0];

        for (int i=1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1],height[i]);
        }

        return leftMax;
    }

    vector<int> getRightMaxArray(vector<int>& height, int& n) {
        vector<int> rightMax(n);

        rightMax[n-1] = height[n-1];

        for (int i=n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        return rightMax;
    }

    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax = getLeftMaxArray(height, n);
        vector<int> rightMax = getRightMaxArray(height, n);

        int sum = 0;
        for (int i=0; i<n; i++) {
            int h = min(leftMax[i], rightMax[i]) - height[i];
            sum += h;
        }

        return sum;
    }
};

//SPACE COMPLEXITY - O(1), TIME COMPLEXITY - O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;
        int ans = 0;

        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] >= lmax) lmax = height[l];
                else ans += lmax - height[l];
                l++;
            }
            else {
                if (height[r] >= rmax) rmax = height[r];
                else ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};