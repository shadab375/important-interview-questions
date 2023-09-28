class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        //i to e = unknown
        //j to i-1 = 1
        //0 to j-1 = 0

        int i = 0, j= 0;
        while (i < n){
            if (arr[i] == 1) i++;
            else{
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
        }
    }
};