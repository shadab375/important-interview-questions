//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n) {
    int i = 0, j = n - 1;
    long long sum = 0;
    sort(arr, arr + n);
    
    while (i < j) {
        sum += abs(arr[i] - arr[j]);
        sum += abs(arr[i+1] - arr[j]);
        i++;
        j--;
    }
    sum += abs(arr[0] - arr[i]);
    
    return sum;
}