//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int nums[], int n) {
        int count = 0;
        int maj = -1;
        
        for (int i=0; i<n; i++) {
            if (count == 0) {
                maj = nums[i];
                count = 1;
            } else if (nums[i] == maj) {
                count++;                
            } else {
                count--;
            }
        }
        
        int freq = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == maj) freq++;
        }
        if (freq > n / 2) return maj;
        
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends