//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

// n = 5, sum = 9 => 1 0 0 0 8
// n = 3, sum = 20 => 2 9 9
// n = 4, sum = 25 =>  1 6 9 9 

class Solution{   
public:
    string smallestNumber(int sum, int n){
        if(sum > 9 * n) return "-1";
        string ans = "";
        
        for(int i = n - 1; i >= 0; i--){
            if(sum > 9){
                ans = "9" + ans;
                sum - =9;
            } else {
                if (i == 0) ans=to_string(sum)+ans;
                else {
                    ans = to_string(sum-1)+ans;
                    sum = 1;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends