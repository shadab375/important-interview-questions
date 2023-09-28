class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n-1;

        /*
        i to k = unknown
        k+1 to e = 2
        j to i-1 = 1
        0 to j-1 = 0
        */

        while (i <= k){
            if (nums[i] == 0){
                swap (nums[i], nums[j]);
                i++;
                j++;
            }
            else if (nums[i] == 1){
                i++;
            }
            else{
                swap(nums[i], nums[k]);
                k--;
            }
        }
    }
};