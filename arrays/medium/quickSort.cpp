//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    
    
    public:
    
    int partition(vector<int>& arr, int pivot, int lo, int hi){

        //0 to j-1 -> <= pivot
        //j to i-1 -> > pivot
        //i to end -> unknown
        int i = lo, j = lo;
        while (i <= hi){
            if (arr[i] <= pivot){           //if smaller -> send to starting 
                swap(arr[i], arr[j]);
                i++;
                j++;
            }                   
            else{                           //else -> let remain
                i++;
            }
        }
        return j-1;
    }
    
    void quickSort(vector<int>& arr, int lo, int hi){
        if (lo > hi) return;
        
        int pivot = arr[hi];
        int pi = partition(arr, pivot, lo, hi);
        quickSort(arr, lo, pi-1);
        quickSort(arr, pi+1, hi);
    }
    
    vector<int> sortArr(vector<int>arr, int n){
        quickSort(arr, 0, n-1);
        return arr;
    }
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends