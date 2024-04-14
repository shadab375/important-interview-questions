//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minValue(int a[], int b[], int n) {
        sort(a, a+n);
        sort(b, b+n);
        long long sum = 0;
        
        int i = 0, j = n - 1;
        while (i < n) {
            sum += a[i] * b[j];
            i++;
            j--;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
// } Driver Code Ends