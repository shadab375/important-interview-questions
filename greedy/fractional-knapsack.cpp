//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
public:
    static bool comp(Item a, Item b) {
        double r1 = (double)a.value/a.weight;
        double r2 = (double)b.value/b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr+n, comp);
        
        double totalValue = 0.0; 
        int totalWeight = 0;
        
        for (int i=0; i<n; i++) {
            if (totalWeight + arr[i].weight <= W) {
                totalWeight += arr[i].weight;
                totalValue += arr[i].value;
            } else {
                int remainWeight = W - totalWeight;
                totalValue += ((double)arr[i].value / arr[i].weight) * remainWeight;
                break;
            }
        }
        
        return totalValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends