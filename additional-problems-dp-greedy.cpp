// Problem 1: Print LCS

#include <bits/stdc++.h>
using namespace std;

string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	for (int i=0; i<=n; i++) dp[i][0] = 0;
	for (int j=0; j<=m; j++) dp[0][j] = 0;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
		}
	}

	string ans = "";
	int i = n, j = m;
	
	while (i>0 && j>0) {
		if (s1[i-1] == s2[j-1]) {
			ans += s1[i-1];
			i--, j--;
		}
		else if (dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else {
			j--;
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

//Problem 2: Print all LCS in lexicographical order
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	int dp[101][101];
	int lcs_len = 0;
	vector<string> res;
	private:
		int lcs(string s, string t, int pos1, int pos2)
		{
			// base condition 
			if(pos1 == s.size() or pos2 == t.size())
				return 0;
			int &ans  = dp[pos1][pos2];
			// if lcs has been computed
			if(ans != -1)
				return ans;
			// if characters are same return previous + 1 else 
			// max of two sequences after removing i'th and j'th 
			// char one by one 
			if(s[pos1] == t[pos2])
				return ans = 1 + lcs(s, t, pos1 + 1, pos2 + 1);
			return ans = max(lcs(s, t, pos1 + 1, pos2), lcs(s, t, pos1, pos2 + 1));
		}
	private:
		void helper(string s, string t, string cur, int pos1, int pos2, int cur_lcs)
		{
			// if currlcs is equal to lcslen then store it 
			if(cur_lcs == lcs_len)
			{
				res.push_back(cur);
				return ;
			}
			// if we are done with all the characters of both string 
			if(pos1 == s.size() or pos2 == t.size())
				return ;
		    // here we have to print all sub-sequences lexicographically, 
    		// that's why we start from 'a'to'z' if this character is 
    		// present in both of them then append it in cur and same 
    		// remaining part 
			for(char ch = 'a'; ch <= 'z'; ch++)
			{
				// f is a flag to tell that we have printed all the 
        		// subsequences corresponding to current character
				bool f = false;
				for(int i = pos1; i < s.size(); i++)
				{
					if(s[i] == ch)
					{
						for(int j = pos2; j < t.size(); j++)
						{
		                // if ch is present in both of them and 
                		// remaining length is equal to remaining 
                		// lcs length then add ch in sub-sequenece 
							if(t[j] == ch and lcs(s, t, i, j) == lcs_len - cur_lcs)
							{
								string new_cur = cur + ch;
								helper(s, t, new_cur, i + 1, j + 1, cur_lcs + 1);
								f = true;
								break;
							}
						}
					}
					// If we found LCS beginning with current character
					if(f)
						break;
				}
			}
		}
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
			memset(dp, -1, sizeof(dp));
			// Find lcs_length
			lcs_len = lcs(s, t, 0, 0);
			// function to get all longest common subsequences
			helper(s, t, "", 0, 0, 0);
			return res;
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends

/*
Problem 3: Smallest window in a string containing all the characters of another string
HardAccuracy: 30.19%Submissions: 129K+Points: 8
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
*/

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        //if length of string p is greater than string s then we return -1.
        if(p.length()>s.length())
        {
            return "-1";
        }
        else
        {
            //using hash tables to store the count of characters in strings.
            int shash[26]={0};
            int phash[26]={0};
            
            //storing the count of characters in string p in hash table.
            for(int i=0;i<p.length();i++)
            {
                phash[p[i]-'a']++;
            }
            
            int counter=0;
            int begin=0;
            int startindex=-1;
            int length=0;
            int minlength=INT_MAX;
            for(int i=0;i<s.length();i++)
            {
                //storing the count of characters in string s in hash table.
                shash[s[i]-'a']++;
                
                //if count of current character in string s is equal to or less 
                //than in string p, we increment the counter.
                if(phash[s[i]]-'a'!=0&&shash[s[i]-'a']<=phash[s[i]-'a'])
                {
                    counter++;
                }
                
                //if all the characters are matched
                if(counter==p.length())
                {
                    //we try to minimize the window.
                    while(shash[s[begin]-'a']>phash[s[begin]-'a']||phash[s[begin]-'a']==0)
                    {
                        if(shash[s[begin]-'a']>phash[s[begin]-'a'])
                        shash[s[begin]-'a']--;
                        begin++;
                    }
                    //updating window size.
                    length=i-begin+1;
                    if(length<minlength)
                    {
                        //if new minimum sub-string is found, we store value
                        //of its starting index for new found window.
                        startindex=begin;
                        minlength=length;
                    }
                    
                }
            }
            
            //returning the smallest window or -1 if no such window is present.
            if(startindex==-1)
                return "-1";
            else
                return s.substr(startindex,minlength);
        }
    }
};

// Problem 4: MCM
//RECURSION + MEMOIZATION

#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == j) return 0;
    int mini = INT_MAX;
    for (int k=i; k<j; k++) {
        int cost = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}


int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return f(1, n-1, arr, dp);
}

//TABULATION

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=1; i<n; i++) {
        dp[i][i] = 0;
    }
    for (int i=n-1; i>=1; i--) {
        for (int j=i+1; j<n; j++) {
            int mini = INT_MAX;
            for (int k=i; k<j; k++) {
                int cost = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}

// Problem 5: Rod Cutting
//RECURSION + MEMOIZATION

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int N, vector<int>& price, vector<vector<int>>& dp){
  if (ind == 0){
		return N * price[0];
	}
	if (dp[ind][N] != -1) return dp[ind][N];
	int notTake = 0 + f(ind-1, N, price, dp);
	int take = INT_MIN;
	int rodLength = ind + 1;
	if (rodLength <= N) take = price[ind] + f(ind, N-rodLength, price, dp);
	return dp[ind][N] = max(take, notTake);
}

int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n, vector<int> (n+1, -1));
	return f(n-1, n, price, dp);
}




//TABULATION

int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n, vector<int> (n+1, 0));
	for (int N=0; N<=n; N++) dp[0][N] = N*price[0];

	for (int ind=1; ind<n; ind++) {
		for (int N=0; N<=n; N++) {
				int notTake = 0 + dp[ind-1][N];
				int take = INT_MIN;
				int rodLength = ind + 1;
				if (rodLength <= N) take = price[ind] + dp[ind][N-rodLength];
				dp[ind][N] = max(take, notTake);
		}
	}
	
	return dp[n-1][n];
}

/*
Problem 6: Boolean Paranthesization
You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).



Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.



As the answer can be very large, return the output modulo 1000000007.



Note :

‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
Example :

Input: 'exp’ = "T|T & F".

Output: 1

Explanation:
There are total 2  ways to parenthesize this expression:
    (i) (T | T) & (F) = F
    (ii) (T) | (T & F) = T
Out of 2 ways, one will result in True, so we will return 1.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
T^T^F    
Sample Output 1 :
0
Explanation For Sample Input 1:
There are total 2  ways to parenthesize this expression:
(i) (T^T)^(F) = F
(ii) (T)^(T^F) = F
Both ways will result in False, so we will return 0.
*/

//RECURSION + MEMOIZATION

#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1000000007;

int f(int i, int j, int isTrue, string& exp, vector<vector<vector<ll>>>& dp) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    for (int ind=i+1; ind<=j-1; ind+=2) {
        ll lT = f(i, ind-1, 1, exp, dp);
        ll lF = f(i, ind-1, 0, exp, dp);
        ll rT = f(ind+1, j, 1, exp, dp);     
        ll rF = f(ind+1, j, 0, exp, dp);

        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT*rT)%mod)%mod;
            else ways = (ways + (lF*rF)%mod + (lF*rT)%mod + (lT*rF)%mod)%mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
            else ways = (ways + (lF*rF)%mod)%mod;
        }
        else {
            if (isTrue) ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
            else ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>> (n+1, vector<ll> (2, -1)));
    return f(0, n-1, 1, exp, dp);
}

//TABULATION

#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1000000007;

int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n - 1; j++) {
            //Base case 1:
            if (i > j) continue;
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2:
                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                // reccurence logic:
                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2) {
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    if (exp[ind] == '&') {
                        if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) %
                        mod) % mod;
                    }
                    else if (exp[ind] == '|') {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT *
                        rT) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}

//RECURSION + MEMOIZATION

class Solution{
public:
    // Function to count the number of ways to parenthesize the boolean expression
    int countWays(int N, string S){
        int i,j,len;
    	int dpTrue[N][N],dpFalse[N][N];
    
    	// Base cases for a single boolean variable
    	for(i = 0;i < N;i+=2){
    		if(S[i]=='T'){
    			dpTrue[i][i]=1;
    			dpFalse[i][i]=0;
    		}else{
    			dpTrue[i][i]=0;
    			dpFalse[i][i]=1;
    		}
    	}
    	
    	// Fill in the table for different lengths of the boolean expression
    	int x=2;
    	while(x < N){
    		for(i = 0;(i+x) < N;i+=2){
    			dpTrue[i][i+x] = dpFalse[i][i+x]=0;
    			for(j = i+1;j < (i+x);j+=2){
    				// Split the boolean expression at the operator
    				if(S[j]=='|'){
    					// Calculate the number of ways using OR operator
    					dpTrue[i][i+x] = (dpTrue[i][i+x] + 
    									dpTrue[i][j-1]*dpTrue[j+1][i+x] +
    									dpTrue[i][j-1]*dpFalse[j+1][i+x] +
    									dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;
    					// Calculate the number of ways using OR operator
    					dpFalse[i][i+x] = (dpFalse[i][i+x] + 
    									dpFalse[i][j-1]*dpFalse[j+1][i+x])%1003;								
    
    				}else if(S[j]=='&'){
    					// Calculate the number of ways using AND operator
    					dpTrue[i][i+x] = (dpTrue[i][i+x] + 
    									dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003 ;
    					// Calculate the number of ways using AND operator
    					dpFalse[i][i+x] =(dpFalse[i][i+x] + 
    									dpFalse[i][j-1]*dpFalse[j+1][i+x] +
    									dpTrue[i][j-1]*dpFalse[j+1][i+x] +
    									dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;
    				}else{
    					// Calculate the number of ways using XOR operator
    					dpTrue[i][i+x] = (dpTrue[i][i+x] + 
    									dpFalse[i][j-1]*dpTrue[j+1][i+x] +
    									dpTrue[i][j-1]*dpFalse[j+1][i+x])%1003 ;
    					// Calculate the number of ways using XOR operator
    					dpFalse[i][i+x] = (dpFalse[i][i+x] + 
    									dpFalse[i][j-1]*dpFalse[j+1][i+x] +
    									dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003 ;
    				}
    			}
    		}
    	    x=x+2;
    	}
    	// Return the total number of ways to parenthesize the boolean expression
    	return dpTrue[0][N-1]%1003;
    }
};

/*
Problem 6: Partition Array for Maximum Sum
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray. Return the largest sum of the given array after partitioning.

Example 1:

Input:
n = 7
k = 3
arr = [1,15,7,9,2,5,10]
Output:
84
Explanation:
arr becomes [15,15,15,9,10,10,10]
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int sol(int i,int k,vector<int>&nums,vector<int>&dp){
        if(i==nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=nums[i],res=0;
        for(int j=i;j-i+1<=k and j<nums.size();j++){
            maxi=max(maxi,nums[j]);
            int next=sol(j+1,k,nums,dp);
            res=max(maxi*(j-i+1)+next,res);
        }
        return dp[i]=res;
    }
    int solve(int n, int k, vector<int>&nums){
        vector<int>dp(n,-1);
        return sol(0,k,nums,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

/*
Problem 7: Palindromic Partitioning
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
*/

#include <bits/stdc++.h>
using namespace std;

//RECURSION + MEMOIZATION

class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string& s, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for (int j=i; j<n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + f(j+1, n, s, dp);
                mini = min(mini, cost);
            }     
        }
        
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, n, s, dp) - 1;
    }
};


//TABULATION

class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }


    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        for (int i=n-1; i>=0; i--) {
            int mini = INT_MAX;
            for (int j=i; j<n; j++) {
                if (isPalindrome(i, j, s)) {
                    int cost = 1 + dp[j+1];
                    mini = min(mini, cost);
                }
                dp[i] = mini;
            }
        }
        return dp[0] - 1;
        
    }
};

/*
Problem 8: Count Square Submatrices with All Ones
Given a N*M matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input:
N = 3
M = 4
matrix [ ][ ] =
                      [ [0, 1, 1, 1],
                        [1, 1, 1, 1], 
                        [0, 1, 1, 1] ]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There are 1 squares of side 3.
Total number of squares = 10 + 4 + 1 =15
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i=0; i<n; i++) dp[i][0] = arr[i][0];
        for (int j=0; j<m; j++) dp[0][j] = arr[0][j];

        for (int i=1; i<n; i++){
            for (int j=1; j<m; j++){
                if (arr[i][j] == 0) dp[i][j] = 0;
                else{
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        
        int sum = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                sum += dp[i][j];
            }
        }

        return sum;
    }
};

/*
Problem 9: LIS
*/
//TABULATION - USED IN PRINTING THE LIS

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i=0; i<n; i++) {
            for (int prev=0; prev<i; prev++) {
                if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};

//BINARY SEARCH

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
        for (int i=1; i<n; i++) {
            if (arr[i] > temp.back()) temp.push_back(arr[i]);
            else {
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }
        return temp.size();
    }
};

/*
Problem 10: Print the LIS
Given an integer n and array of integers, returns the Longest Increasing subsequence which is lexicographically smallest corresponding to the indices of the elements.
LIS  of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}. 
 

Note - A subsequence S1 is lexicographically smaller than a subsequence S2 if in the first position where a and b differ, subsequence a has a letter that appears earlier in the array than the corresponding letter in b.

Example 1:

Input:
n = 16
arr = [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
Output:
0 2 6 9 13 15 
Explanation:
longest Increasing subsequence is 0 2 6 9 13 15  and the length of the longest increasing subsequence is 6.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n, 1), hash(n);
  int lastIndex = 0;
  int maxi = 1;
  
  for (int i=0; i<n; i++) {
      hash[i] = i;
      for(int prev=0; prev<i; prev++) {
          if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
              dp[i] = dp[prev] + 1;
              hash[i] = prev;
          }
      }
      if (dp[i] > maxi) {
          maxi = dp[i];
          lastIndex = i;
      }
  }
  
  vector<int> temp;
  temp.push_back(arr[lastIndex]);
  while (hash[lastIndex] != lastIndex) {
      lastIndex = hash[lastIndex];
      temp.push_back(arr[lastIndex]);
  }
  reverse(temp.begin(), temp.end());
  return temp;
}

/*
Problem 11: Number of LIS
Given an integer array arr, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

Example:

Input:
n = 5
arr = [1,3,5,4,7]
Output:
2
Explanation:
The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;

        for (int i=0; i<n; i++) {
            for (int prev=0; prev<i; prev++) {
                if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }
                else if (arr[prev] < arr[i] && dp[prev] + 1 == dp[i]) {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int nos = 0;
        for (int i=0; i<n; i++) {
            if (dp[i] == maxi) nos += cnt[i];
        }
        return nos;
    }
};

/*
Problem 12: Longest bitonic subsequence
Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
 

Example 1:

Input: 
n = 5
nums = [1, 2, 5, 3, 2]
Output: 
5
Explanation: 
The sequence {1, 2, 5} is
increasing and the sequence {3, 2} is 
decreasing so merging both we will get 
length 5.
*/
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int> dp1(n, 1), dp2(n, 1);
	int maxi = 1;

	for (int i=0; i<n; i++) {
		for (int prev=0; prev<i; prev++) {
			if (arr[prev] < arr[i] && dp1[prev] + 1 > dp1[i]) {
				dp1[i] = dp1[prev] + 1;
			}
		}
	}

	for (int i=n-1; i>=0; i--) {
		for (int prev=n-1; prev>i; prev--) {
			if (arr[prev] < arr[i] && dp2[prev] + 1 > dp2[i]) {
				dp2[i] = dp2[prev] + 1;
			}
		}
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
	}

	return maxi;

}

/*
Problem 13: Largest Divisible Subset
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple sequences with the largest size, return any of them.

Example 1:

Input:
n = 3
arr = [1,2,3]
Output:
[1,2]
Explanation:
Largest Divisble Subset is [1,2].
Example 2:

Input:
n = 4
arr = [1,2,4,8]
Output:
[1,2,4,8]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<int> dp(n, 1), hash(n);
        int lastIndex = 0;
        int maxi = 1;
        
        for (int i=0; i<n; i++) {
            hash[i] = i;
            for(int prev=0; prev<i; prev++) {
                if (arr[i] % arr[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

/*
Problem 14: Longest valid Parentheses
Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Example 1:

Input: S = ((()
Output: 2
Explaination: The longest valid 
parenthesis substring is "()".
Example 2:

Input: S = )()())
Output: 4
Explaination: The longest valid 
parenthesis substring is "()()".
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        int ans = 0;
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == ')' and st.size() and st.top().first == '('){
                st.pop();
                ans = max(ans,i-(st.size() ? st.top().second : -1));
            }else{
                st.push({s[i],i});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

/*
Problem 15: The Painter's Partition Problem-II
Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


Example 1:

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35
Example 2:

Input:
n = 4
k = 2
arr[] = {10,20,30,40}
Output: 60
Explanation: The most optimal way to paint:
Painter 1 allocation : {10,20,30}
Painter 2 allocation : {40}
Job will be complete at time = 60
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  
    bool isPossible(int arr[], int n, int mid, int m){
        int painters = 1, sum = 0;
        for (int i=0; i<n; i++){
            sum += arr[i];
            
            if (sum > mid){
                painters++;
                sum = arr[i];
            }
        }
        return painters <= m;
    }
    long long minTime(int arr[], int n, int m)
    {
          long long sum = 0;
          int maxi = 0;
          for (int i=0; i<n; i++){
              sum += arr[i];
              maxi = max(maxi, arr[i]);
          }
          
          int lo = maxi;
          long long hi = sum;
          int ans = 0;
          
          while (lo <= hi){
              int mid = lo + (hi - lo)/2;
              if (isPossible(arr, n, mid, m) == true){
                  ans = mid;
                  hi = mid - 1;
              }
              else{
                  lo = mid + 1;
              }
          }
          return ans;
    }
};

/*
Problem 16: Maximum Profit
In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days in an array A[ ] and a positive integer K, find out the maximum profit a person can make in at-most K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.


Example 1:

Input: K = 2, N = 6
A = {10, 22, 5, 75, 65, 80}
Output: 87
Explaination: 
1st transaction: buy at 10 and sell at 22. 
2nd transaction : buy at 5 and sell at 80.
*/
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // table to store results of subproblems profit[t][i] stores maximum
        // profit using atmost t transactions up to day i (including day i)
        int profit[K + 1][N + 1];

        // For day 0, you can't earn money irrespective of how many times you
        // trade
        for (int i = 0; i <= K; i++) profit[i][0] = 0;

        // profit is 0 if we don't do any transation (i.e. k =0)
        for (int j = 0; j <= N; j++) profit[0][j] = 0;

        // fill the table in bottom-up fashion
        for (int i = 1; i <= K; i++) {
            int prevDiff = INT_MIN;
            for (int j = 1; j < N; j++) {
                prevDiff = max(prevDiff, profit[i - 1][j - 1] - A[j - 1]);
                profit[i][j] = max(profit[i][j - 1], A[j] + prevDiff);
            }
        }

        return profit[K][N - 1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
Problem 17: Max min Height
You have a garden with n flowers lined up in a row. The height of ith flower is ai units. You will water them for k days. In one day you can water w continuous flowers (you can do this only once in a single day). Whenever you water a flower its height increases by 1 unit. You need to maximize the height of the smallest flower all the time.

Example 1:

Input:
n=6
k=2
w=3
a[]={2,2,2,2,1,1}
Output:
2
Explanation:
Water last three flowers for first day & 
first three flowers for second day.The 
new heights will be {3,3,3,3,2,2}
*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
         // Function to check if current minimum height is valid or not.
        bool isvalid(vector <int> &a, int n, int k, int w, long long int mid)
        {
            // Array to store the prefix sum of the previous heights.
            long long int ps[n];
            fill(ps, ps+n, 0ll);
            long long int ans = 0;

            // Iterating over each height.
            for(long long int i = 0; i < n; i++)
            {
                // Calculating the prefix sum and checking if the current height is less than the current minimum height.
                if(i - 1 >= 0)
                    ps[i] += ps[i-1];
                if(a[i] + ps[i] < mid)
                {
                    // Updating the prefix sum and the total number of adjustments required.
                    long long int e = mid - a[i] - ps[i];
                    ans += e;
                    ps[i] += e;

                    // Reducing the height adjustments for the next window of width w.
                    if(i + w < n)
                        ps[i+w] -= e;
                }
            }
            return (ans <= k); // Checking if the total adjustments required is less than or equal to k.
        }

        // Function to maximize the minimum height.
        long long int maximizeMinHeight(int n, int k, int w, vector <int> &a)
        {
            int ans = 0;
            long long int l = 0, h = 1e14;

            // Binary search to find the maximum valid minimum height.
            while(l <= h)
            {
                long long int mid = (l + h) / 2;

                // Checking if the current height is valid.
                if(isvalid(a, n, k, w, mid))
                {
                    l = mid + 1; // Updating the lower bound.
                    ans = mid; // Updating the maximum valid minimum height.
                }
                else
                {
                    h = mid - 1; // Updating the upper bound.
                }
            }
            return ans; // Returning the maximum valid minimum height.
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends

/*
Problem 18: Walls Coloring II
There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls on the occasion of New Year. Alexa can color each wall with one of the K colors. The cost associated with coloring each wall with a particular color is represented by a 2D costs array of size N * K. For example, costs[0][0] is the cost of coloring wall 0 with color 0; costs[1][2] is the cost of coloring wall 1 with color 2, and so on... Find the minimum cost to color all the walls such that no two adjacent walls have the same color.

Note: If you are not able to paint all the walls, then you should return -1.

Example 1:

Input:
N = 4, K = 3
costs[][] = {{1, 5, 7},
             {5, 8, 4},
             {3, 2, 9},
             {1, 2, 4}}

Output:
8
Explanation:
Paint wall 0 with color 0. Cost = 1
Paint wall 1 with color 2. Cost = 4
Paint wall 2 with color 1. Cost = 2
Paint wall 3 with color 0. Cost = 1
Total Cost = 1 + 4 + 2 + 1 = 8
Example 2:

Input:
N = 5, K = 1
costs[][] = {{5},
             {4},
             {9},
             {2},
             {1}}
Output:
-1
Explanation:
It is not possible to color all the walls under the given conditions.
*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 0) return 0;
        // Stores the first minimum value
        int min1 = INT_MAX;
        // Stores the second most minimum value
        int min2 = INT_MAX;
        // Creating a dp 2D array of size n*k
        vector<vector<int>> dp(n, vector<int>(k));
        for (int i = 0; i < k; i++) {
            dp[0][i] = costs[0][i];
            if (costs[0][i] < min1) {
                min2 = min1;
                min1 = costs[0][i];
            } else if (costs[0][i] < min2) {
                min2 = costs[0][i];
            }
        }
        if (n == 1) {
            return min1;
        }
        // Stores the current minimum value in a given iteration
        int cmin1 = INT_MAX;
        // Stores the second most current minimum value in a given iteration
        int cmin2 = INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (dp[i - 1][j] != min1) {
                    dp[i][j] = costs[i][j] + min1;
                }
                else {
                    dp[i][j] = costs[i][j] + min2;
                }
                    
                if (dp[i][j] < cmin1) {
                    cmin2 = cmin1;
                    cmin1 = dp[i][j];
                } 
                else if (dp[i][j] < cmin2) {
                    cmin2 = dp[i][j];
                }
            }
            min1 = cmin1;
            min2 = cmin2;
            cmin1 = INT_MAX;
            cmin2 = INT_MAX;
        }
        // If min1 value is less than 0, implies the answer is not possible
        if (min1 < 0) {
            return -1;
            
        }
        return min1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends

/*
Problem 19: Burst Balloons
You are given N balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array arr. You are asked to burst all the balloons.
If you burst the ith balloon, you will get arr[ i - 1 ] * arr[ i ] * arr[ i + 1] coins. If i - 1, or i + 1 goes out of the bounds of the array, consider it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input:
N = 4
arr[ ] = {3, 1, 5, 8}
Output: 167
Explanation: 
arr[ ] = {3, 1, 5, 8}  - - > {3, 5, 8} - - > {3, 8} - - > { 8} - -> { }
coins = 3 *1 *5,      +      3*5*8     +   1*3*8   +  1*8*1   = 167
 
 

Example 2:

Input:
N = 2
arr[ ] = {1, 10}
Output: 20
*/

//RECURSION + MEMOIZATION

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    int f(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for (int k=i; k<=j; k++) {
            int cost = a[i-1]*a[k]*a[j+1] + f(i, k-1, a, dp) + f(k+1, j, a, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(), 1);
        a.push_back(1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, a, dp);
    }
};


//TABULATION

class Solution {
public:

    int maxCoins(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(), 1);
        a.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int i=n; i>=1; i--) {
            for (int j=1; j<=n; j++) {
                if (i>j) continue;
                int maxi = INT_MIN;
                for (int k=i; k<=j; k++) {
                    int cost = a[i-1]*a[k]*a[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};

/*
Problem 20: Queries on a Matrix
You are given a matrix of dimension n*n. All the cells are initially, zero. You are given Q queries, which contains 4 integers a b c d where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix. Now, all the cells of this submatrix have to be incremented by one. After all the Q queries have been performed. Your task is to find the final resulting Matrix.
Note : Zero-Based Indexing is used for cells of the matrix. 
 

Example 1:

Input: n = 6, q = 6,
Queries = {
{4,0,5,3},
{0,0,3,4},
{1,2,1,2},
{1,1,2,3},
{0,0,3,1},
{1,0,2,4}}.
Output: 
2 2 1 1 1 0
3 4 4 3 2 0 
3 4 3 3 2 0
2 2 1 1 1 0
1 1 1 1 0 0
1 1 1 1 0 0
Explanation:After incrementing all the
sub-matrices of given queries we will 
get the final output.

 

 

Example 2:

Input: n = 4, q = 2,
Queries = {
{0,0,3,3},
{0,0,2,2}}.
Output: 
2 2 2 1 
2 2 2 1  
2 2 2 1 
1 1 1 1 
Explanation:After incrementing all the
sub-matrices of given queries we will
get the final output.
*/
class Solution {
  public:
    //Function to solve the queries.
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        
        //creating a matrix of size n+2 x n+2 and initializing it with 0s.
        vector<vector<int>> matrix(n + 2, vector<int>(n + 2, 0));
        
        //creating two additional matrices (row and col), each of size n+2 x n+2
        //and initializing them with 0s.
        vector<vector<int>> row(n + 2, vector<int>(n + 2, 0));
        vector<vector<int>> col(n + 2, vector<int>(n + 2, 0));
        
        //iterating over all the queries.
        for (auto i : Queries) {
            int a = i[0];    //extracting the values from the query.
            int b = i[1];
            int c = i[2];
            int d = i[3];
            
            //updating the row and col matrices as per the queries.
            row[a][b]++;
            row[c + 1][b]--;
            col[a][d + 1]--;
            col[c + 1][d + 1]++;
        }
        
        //updating the values of row and col matrices by summing up
        //the values of previous rows.
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                row[j][i] += row[j - 1][i];
                col[j][i] += col[j - 1][i];
            }
        }
        
        //computing the values of the matrix by adding the values of
        //the row and col matrices at each cell.
        for (int i = 0; i < n; i++) {
            matrix[i][0] = row[i][0] + col[i][0];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[j][i] += matrix[j][i - 1] + row[j][i] + col[j][i];
            }
        }
        
        //creating a result matrix of size n x n and copying the values
        //of the matrix into it.
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) res[i][j] = matrix[i][j];
        
        //returning the result matrix.
        return res;
    }
};

/*
Problem 21: convert-to-strictly-increasing-array
Given an array nums of n positive integers. Find the minimum number of operations required to modify the array such that array elements are in strictly increasing order (nums[i] < nums[i+1]).
Changing a number to greater or lesser than original number is counted as one operation.

Note: Array elements can become negative after applying operation.

Example 1:

Input:
n = 6
nums = [1, 2, 3, 6, 5, 4]
Output: 
2
Explanation: 
By decreasing 6 by 2 and increasing 4 by 2, nums will be like [1, 2, 3, 4, 5, 6] which is stricly increasing.
Example 2:

Input: 
n = 4
nums = [1, 1, 1, 1]
Output: 
3
Explanation: 
One such array after operation can be [-2, -1, 0, 1]. We require atleast 3 operations for this example.
*/
class Solution {
  public:

    int min_operations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < i; j++) {
                // If nums[i] is greater than nums[j] then it can be added to the set of
                // LIS
                if (nums[i] > nums[j])
                    if (nums[i] - nums[j] > i - j - 1)
                        temp = max(temp, dp[j]);
            }
            // length of maximum increasing subsequnce whose last element is nums[i]
            dp[i] = max(dp[i], 1 + temp);
        }
        // total opeartion needs to  apply
        return n - *max_element(dp.begin(), dp.end());
    }
};

/*
Problem 22: Brackets in Matrix Chain Multiplication
Given an array p[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

NOTE:

Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also Please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
As there can be multiple possible answers, the console would print "True" for the correct string and "False" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.
Example 1:

Input: 
n = 5
p[] = {40, 20, 30, 10, 30}
Output: 
True
Explaination: 
Let's divide this into matrix(only 4 are possible) 
[ [40, 20] -> A
, [20, 30] -> B
, [30, 10] ->C
, [10, 30] -> D ]
First we perform multiplication of B & C -> (BC)
then we multiply A to (BC) -> (A(BC))
then we multiply D to (A(BC)) -> ((A(BC))D)
so the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.
*/
// Back-end complete function Template for C++
class Solution{
public:
    string st;
    
    // Function to print the parenthesis of matrix chain multiplication
    void printParenthesis(int i, int j, int n, int *bracket, char &name){
        // If i and j are equal, it means only one matrix is remaining
        if (i == j){
            st += name; // add the name of matrix to the string
            name++; // increment the name for the next matrix
            return;
        }
        st += '('; // add '(' to the string
        printParenthesis(i, *((bracket+i*n)+j), n,bracket, name); // recursively print the parenthesis for the left side of the split
        printParenthesis(*((bracket+i*n)+j) + 1, j,n, bracket, name); // recursively print the parenthesis for the right side of the split
        st += ')'; // add ')' to the string
    }
    
    // Function to calculate the minimum number of operations needed to multiply the matrices
    string matrixChainOrder(int p[], int n)
    {
        int m[n][n]; // create a 2D array to store the minimum number of operations
        int bracket[n][n]; // create a 2D array to store the split position for each matrix multiplication
        for (int i = 1; i < n; i++)
            m[i][i] = 0; // initialize the diagonal elements to 0
        for (int L = 2; L < n; L++){ // iterate over the lengths of the sequences
            for (int i = 1; i < n-L+1; i++){ // iterate over the starting indices of the sequences
                int j = i + L - 1; // calculate the ending index of the sequence
                m[i][j] = INT_MAX; // set the minimum number of operations to a large value at first
                for (int k = i; k <= j-1; k++){ // iterate over possible split positions
                    int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; // calculate the number of operations needed for this split
                    if (q < m[i][j]){ // if this split has less operations than the current minimum, update the values
                        m[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        char name = 'A'; // initialize the name of the matrices
        printParenthesis(1, n-1, n, (int *)bracket, name); // call the function to print the parenthesis
        return st; // return the string containing the parenthesis
    }
};


/*
Problem 23: Longest Path in a matrix
Given a n*m matrix, find the maximum length path (starting from any cell) such that all cells along the path are in strictly increasing order.

We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1).
 

Example 1:

Input: matrix = {{1,2,9},{5,3,8},{4,6,7}}
Output: 7
Explanation: The longest increasing path is
{1,2,3,6,7,8,9}.
Example 2:

Input: matrix = {{3,4,5},{3,2,6},{2,2,1}}
Output: 4
Explanation: The longest increasing path is
{3,4,5,6}.
*/
class Solution {
public:
    //Function to perform depth-first search to find the longest increasing path.
    int DFS(vector<vector<int>>& matrix, int y, int x, int val, vector<vector<int>>& hash)
    {
        //Checking if we are out of bounds.
        if(y < 0 || y >= matrix.size() || x <0 || x >= matrix[0].size())
            return 0;
        
        //Checking if the current cell's value is greater than the previous cell's value.
        if(matrix[y][x] > val)
        {
            //Checking if this path has already been searched.
            if(hash[y][x] != 0) return hash[y][x];

            //Performing DFS on all adjacent cells and finding the maximum length.
            int a = DFS(matrix, y, x+1,matrix[y][x], hash) + 1;
            int b = DFS(matrix, y, x-1,matrix[y][x], hash) + 1;
            int c = DFS(matrix, y+1, x,matrix[y][x], hash) + 1;
            int d = DFS(matrix, y-1, x,matrix[y][x], hash) + 1;

            //Storing the maximum length in the hash array for memoization.
            hash[y][x] = max(a, max(b,max(c, d)));
            return hash[y][x];
        }
        
        //If the current cell's value is not greater than the previous cell's value, return 0.
        return 0;
    }
    
    //Function to find the longest increasing path in the matrix.
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //Checking if the matrix is empty.
        if(matrix.size() == 0) return 0;

        int Max = 0;
        vector<int> tem(matrix[0].size(),0);

        //Creating a hash array to store the lengths of already searched paths.
        vector<vector<int>> hash(matrix.size(), tem);

        //Performing DFS on each cell in the matrix and finding the maximum length.
        for(int i = 0; i< matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                Max = max(DFS(matrix, i, j, INT_MIN, hash), Max);

        //Returning the maximum length found.
        return Max;
    }
};

/*
Problem 24: Longest Zig-Zag Sub Sequence
Given an array nums of n positive integers. The task is to find the longest Zig-Zag subsequence problem such that all elements of this are alternating (numsi-1 < numsi > numsi+1 or numsi-1 > numsi < numsi+1).
 

Example 1:

Input: nums = {1,5,4}
Output: 3
Explanation: The entire sequenece is a 
Zig-Zag sequence.
Examplae 2:

Input: nums = {1,17,5,10,13,15,10,5,16,8}
Ooutput: 7
Explanation: There are several subsequences
that achieve this length. 
One is {1,17,10,13,10,16,8}.
*/
class Solution {
    public:
        int ZigZagMaxLength(vector<int>&nums){
            // If there are less than 2 elements in the array, return the size of the array
            if(nums.size() < 2)
                return nums.size();
            
            // Initialize the variables for tracking the length of zigzag sequence
            int up = 1, down = 1;
            
            // Iterate through the array starting from index 1
            for(int i = 1; i < nums.size(); i++){
                // If the current element is greater than the previous element, increase the length of the "up" sequence
                if(nums[i] > nums[i-1])
                    up = down + 1;
                // If the current element is less than the previous element, increase the length of the "down" sequence
                else if(nums[i] < nums[i-1])
                    down  = up + 1;
            }
            
            // Return the maximum length of the zigzag sequence
            return max(up, down);
        }
};

/*
Problem 25: Better String
Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.

Example 1:

Input:
str1 = "gfg", str2 = "ggg"
Output: "gfg"
Explanation: "gfg" have 6 distinct subsequences whereas "ggg" have 3 distinct subsequences. 
Example 2:

Input: str1 = "a", str2 = "b"
Output: "a"
Explanation: Both the strings have only 1 distinct subsequence. 
*/
// Back-end complete function Template for C++

class Solution {
  public:
    int countSub(string str) {
        // Create an array to store index
        // of last
        vector<int> last(256, -1);

        // Length of input string
        int n = str.length();

        // dp[i] is going to store count of distinct
        // subsequences of length i.
        int dp[n + 1];

        // Empty substring has only one subsequence
        dp[0] = 1;

        // Traverse through all lengths from 1 to n.
        for (int i = 1; i <= n; i++) {
            // Number of subsequences with substring
            // str[0..i-1]
            dp[i] = 2 * dp[i - 1];

            // If current character has appeared
            // before, then remove all subsequences
            // ending with previous occurrence.
            if (last[str[i - 1]] != -1) dp[i] = dp[i] - dp[last[str[i - 1]]];

            // Mark occurrence of current character
            last[str[i - 1]] = (i - 1);
        }

        return dp[n];
    }
    string betterString(string str1, string str2) {
        int a = countSub(str1), b = countSub(str2);
        if (a < b) return str2;
        return str1;
    }
};


/*
Problem 26: Longest Increasing Path in a Matrix
Given a matrix with n rows and m columns. Your task is to find the length of the longest increasing path in matrix, here increasing path means that the value in the specified path increases. For example if a path of length k has values a1, a2, a3, .... ak  , then for every i from [2,k] this condition must hold ai > ai-1.  No cell should be revisited in the path.
From each cell, you can either move in four directions: left, right, up, or down. You are not allowed to move diagonally or move outside the boundary.


Example 1:

Input:
n = 3, m = 3
matrix[][] = {{1 2 3},
              {4 5 6},
              {7 8 9}}
Output: 
5
Explanation: 
The longest increasing path is 
{1, 2, 3, 6, 9}. 
Example 2:

Input:
n = 3, m = 3
matrix[][] = {{3 4 5},
              {6 2 6},
              {2 2 1}}
Output: 
4
Explanation:
The longest increasing path is
{3, 4, 5, 6}.
*/

class Solution {
  public:
    // DFS function to find the length of the longest increasing path
    int DFS(vector<vector<int>>& matrix, int y, int x, int val,
            vector<vector<int>>& hash) {
        // Base case: if out of bounds, return 0
        if (y < 0 || y >= matrix.size() || x < 0 || x >= matrix[0].size())
            return 0;
        // If current value is greater than previous value, continue the path
        if (matrix[y][x] > val) {
            // If the path has already been searched, return the stored value
            if (hash[y][x] != 0)
                return hash[y][x];
            // Find the length of the path by recursively calling DFS in all directions
            int a = DFS(matrix, y, x + 1, matrix[y][x], hash) + 1;
            int b = DFS(matrix, y, x - 1, matrix[y][x], hash) + 1;
            int c = DFS(matrix, y + 1, x, matrix[y][x], hash) + 1;
            int d = DFS(matrix, y - 1, x, matrix[y][x], hash) + 1;
            // Store the maximum length in the hash table
            hash[y][x] = max(a, max(b, max(c, d)));
            return hash[y][x];
        }
        // If current value is not greater than previous value, return 0
        return 0;
    }
    
    // Function to find the length of the longest increasing path in the matrix
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        // If the matrix is empty, return 0
        if (matrix.size() == 0) return 0;
        int Max = 0;
        vector<int> tem(matrix[0].size(), 0);
        vector<vector<int>> hash(matrix.size(), tem);
        // Iterate through each element in the matrix and find the maximum path length
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                Max = max(DFS(matrix, i, j, INT_MIN, hash), Max);
        return Max;
    }
};

