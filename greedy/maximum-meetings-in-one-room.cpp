//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        int i, end;
        vector<int> ans;
        vector<pair<pair<int, int>, int>> a; // {{finish_time, start_time}, number}
        
        for (int i=0; i<N; i++) {
            a.push_back({{F[i], S[i]}, i+1});
        }
        
        sort(a.begin(), a.end());
        ans.push_back(a[0].second);
        end = a[0].first.first;
        
        for (int i=1; i<N; i++) {
            if (a[i].first.second > end) { // if starting time of i'th job is greater than ending time of previous job
                ans.push_back(a[i].second);
                end = a[i].first.first;
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends