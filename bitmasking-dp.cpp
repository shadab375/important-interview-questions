// Problem 0: given a set, count how many subsets have sum of elements greater than or equal to a given value.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& set, int setSize, int val) {
    int count = 0;
    for (int x = 0; x < pow(2, setSize); ++x) {
        int sum = 0;
        for (int k = 0; k < setSize; ++k) {
            if (x & (1 << k)) {  // Check if kth bit is set in x
                sum += set[k];
            }
        }
        if (sum >= val) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> set = {1, 2, 3, 4}; // Example set
    int setSize = set.size();
    int val = 5; // Example value

    int result = solve(set, setSize, val);
    cout << "Number of subsets with sum greater than or equal to " << val << ": " << result << endl;

    return 0;
}

// Problem 1: Finding the Shortest Hamiltonian Walk
// Given a graph, find the shortest Hamiltonian walk that visits all vertices exactly once.

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solveShortestHamiltonianWalk(vector<vector<int>>& dp, vector<vector<int>>& adjList) {
    int n = adjList.size();
    int totalVertices = (1 << n);

    dp.assign(totalVertices, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < totalVertices; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (dp[mask][i] == INF || !(mask & (1 << i)))
                continue;

            for (int j : adjList[i]) {
                if (mask & (1 << j)) {
                    dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + 1);
                }
            }
        }
    }

    int shortestWalkLength = INF;
    for (int i = 1; i < n; ++i) {
        if (!adjList[i].empty()) {
            shortestWalkLength = min(shortestWalkLength, dp[totalVertices - 1][i] + 1);
        }
    }

    return (shortestWalkLength == INF) ? -1 : shortestWalkLength;
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 2, 3},
        {0, 2, 3},
        {0, 1, 3},
        {0, 1, 2}
    };

    vector<vector<int>> dp;
    int shortestWalkLength = solveShortestHamiltonianWalk(dp, adjList);
    cout << "Shortest Hamiltonian walk length: " << shortestWalkLength << endl;

    return 0;
}

// Problem 2: Finding the Number of Hamiltonian Walks
// Given a graph, find the number of Hamiltonian walks that visit all vertices exactly once and return to the starting vertex.
#include <bits/stdc++.h>
using namespace std;

int solveNumberOfHamiltonianWalks(vector<vector<int>>& dp, vector<vector<int>>& adjList) {
    int n = adjList.size();
    int totalVertices = (1 << n);

    dp.assign(totalVertices, vector<int>(n, 0));
    dp[1][0] = 1;

    for (int mask = 1; mask < totalVertices; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i)))
                continue;

            for (int j : adjList[i]) {
                if (!(mask & (1 << j))) {
                    dp[mask][j] += dp[mask ^ (1 << j)][i];
                }
            }
        }
    }

    return dp[totalVertices - 1][n - 1];
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 2, 3},
        {0, 2, 3},
        {0, 1, 3},
        {0, 1, 2}
    };

    vector<vector<int>> dp;
    int numberOfHamiltonianWalks = solveNumberOfHamiltonianWalks(dp, adjList);
    cout << "Number of Hamiltonian walks: " << numberOfHamiltonianWalks << endl;

    return 0;
}

// Problem 3: Finding the Number of Simple Paths
// Given a graph, find the number of simple paths between two vertices.
#include <bits/stdc++.h>
using namespace std;

int solveNumberOfSimplePaths(vector<vector<int>>& dp, vector<vector<int>>& adjList) {
    int n = adjList.size();
    int totalVertices = (1 << n);

    dp.assign(totalVertices, vector<int>(n, 0));
    dp[1][0] = 1;

    for (int mask = 1; mask < totalVertices; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i)))
                continue;

            for (int j : adjList[i]) {
                if (!(mask & (1 << j))) {
                    dp[mask][j] += dp[mask ^ (1 << j)][i];
                }
            }
        }
    }

    int numberOfSimplePaths = 0;
    for (int i = 1; i < n; ++i) {
        numberOfSimplePaths += dp[totalVertices - 1][i];
    }
    return numberOfSimplePaths / 2; // Divided by 2 because each path is considered twice
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2}
    };

    vector<vector<int>> dp;
    int numberOfSimplePaths = solveNumberOfSimplePaths(dp, adjList);
    cout << "Number of simple paths: " << numberOfSimplePaths << endl;

    return 0;
}


// Problem 4: Check for Existence of Hamiltonian Walk
// Given a graph, check if there exists a Hamiltonian walk that visits all vertices exactly once and returns to the starting vertex.
#include <bits/stdc++.h>
using namespace std;

bool existsHamiltonianWalk(vector<vector<int>>& dp, vector<vector<int>>& adjList) {
    int n = adjList.size();
    int totalVertices = (1 << n);

    dp.assign(totalVertices, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 1;
    }

    for (int mask = 1; mask < totalVertices; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!dp[mask][i] || !(mask & (1 << i)))
                continue;

            for (int v : adjList[i]) {
                if (!(mask & (1 << v))) {
                    dp[mask | (1 << v)][v] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dp[totalVertices - 1][i]) {
            return true;
        }
    }

    return false;
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 2, 3},
        {0, 2, 3},
        {0, 1, 3},
        {0, 1, 2}
    };

    vector<vector<int>> dp;
    bool hasHamiltonianWalk = existsHamiltonianWalk(dp, adjList);
    cout << "Existence of Hamiltonian walk: " << (hasHamiltonianWalk ? "Yes" : "No") << endl;

    return 0;
}


// Problem 5: Finding the Shortest Hamiltonian Cycle
// Given a graph, find the shortest Hamiltonian cycle that visits all vertices exactly once.
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solveShortestHamiltonianCycle(vector<vector<int>>& dp, vector<vector<int>>& adjList) {
    int n = adjList.size();
    int totalVertices = (1 << n);

    dp.assign(totalVertices, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < totalVertices; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (dp[mask][i] == INF || !(mask & (1 << i)))
                continue;

            for (int v : adjList[i]) {
                if (mask & (1 << v)) {
                    dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][i] + 1);
                }
            }
        }
    }

    int shortestCycleLength = INF;
    for (int i = 1; i < n; ++i) {
        if (adjList[i].size() && dp[totalVertices - 1][i] != INF) {
            shortestCycleLength = min(shortestCycleLength, dp[totalVertices - 1][i] + 1);
        }
    }

    return shortestCycleLength;
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 2, 3},
        {0, 2, 3},
        {0, 1, 3},
        {0, 1, 2}
    };

    vector<vector<int>> dp;
    int shortestCycleLength = solveShortestHamiltonianCycle(dp, adjList);
    cout << "Shortest Hamiltonian cycle length: " << shortestCycleLength << endl;

    return 0;
}


int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<vector<int>> dp;
    int shortestCycleLength = solveShortestHamiltonianCycle(dp, graph);
    cout << "Shortest Hamiltonian cycle length: " << shortestCycleLength << endl;

    return 0;
}

// Problem 6: Finding the Number of Hamiltonian Cycles
// Given a graph, find the number of Hamiltonian cycles that visit all vertices exactly once.
#include <bits/stdc++.h>
using namespace std;

int solveNumberOfHamiltonianCycles(vector<vector<int>>& dp, vector<vector<int>>& adjList) {
    int n = adjList.size();
    int totalVertices = (1 << n);

    dp.assign(totalVertices, vector<int>(n, 0));
    dp[1][0] = 1;

    for (int mask = 1; mask < totalVertices; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i)))
                continue;

            for (int v : adjList[i]) {
                if (!(mask & (1 << v))) {
                    dp[mask | (1 << v)][v] += dp[mask][i];
                }
            }
        }
    }

    return dp[totalVertices - 1][0];
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 2, 3},
        {0, 2, 3},
        {0, 1, 3},
        {0, 1, 2}
    };

    vector<vector<int>> dp;
    int numberOfHamiltonianCycles = solveNumberOfHamiltonianCycles(dp, adjList);
    cout << "Number of Hamiltonian cycles: " << numberOfHamiltonianCycles << endl;

    return 0;
}


// Problem 7: Finding the Number of Simple Cycles
// Given a graph, find the number of simple cycles of length k starting and ending at a given vertex.
#include <bits/stdc++.h>
using namespace std;

int solveNumberOfSimpleCycles(vector<vector<int>>& dp, vector<vector<int>>& adjList) {
    int n = adjList.size();
    int totalVertices = (1 << n);

    dp.assign(totalVertices, vector<int>(n, 0));
    dp[1][0] = 1;

    for (int mask = 1; mask < totalVertices; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i)))
                continue;

            for (int v : adjList[i]) {
                if (!(mask & (1 << v))) {
                    dp[mask | (1 << v)][v] += dp[mask][i];
                }
            }
        }
    }

    int numberOfSimpleCycles = 0;
    for (int i = 1; i < n; ++i) {
        numberOfSimpleCycles += dp[totalVertices - 1][i];
    }
    return numberOfSimpleCycles;
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2}
    };

    vector<vector<int>> dp;
    int numberOfSimpleCycles = solveNumberOfSimpleCycles(dp, adjList);
    cout << "Number of simple cycles: " << numberOfSimpleCycles << endl;

    return 0;
}


//  Problem 8: Checking for Existence of Hamiltonian Cycle
#include <bits/stdc++.h>
using namespace std;

bool existsHamiltonianCycle(vector<vector<int>>& dp, vector<vector<int>>& adjList) {
    int n = adjList.size();
    int totalVertices = (1 << n);

    dp.assign(totalVertices, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 1;
    }

    for (int mask = 1; mask < totalVertices; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!dp[mask][i] || !(mask & (1 << i)))
                continue;

            for (int v : adjList[i]) {
                if (!(mask & (1 << v))) {
                    dp[mask | (1 << v)][v] = dp[mask][i] + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (adjList[i].size() && dp[totalVertices - 1][i] == n) {
            return true;
        }
    }

    return false;
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 2, 3},
        {0, 2, 3},
        {0, 1, 3},
        {0, 1, 2}
    };

    vector<vector<int>> dp;
    bool hasHamiltonianCycle = existsHamiltonianCycle(dp, adjList);
    cout << "Existence of Hamiltonian cycle: " << (hasHamiltonianCycle ? "Yes" : "No") << endl;

    return 0;
}

/*
Problem 9: Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job. 
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int cost[21][21];
int dp[21][(1<<21)];

int solve(int i, int mask, int& n)
{
    if(i == n)
        return 0;

    if(dp[i][mask] != -1)
        return dp[i][mask];

    int answer = INT_MAX;
    for(int j = 0; j < n; j++)
    {
        if(mask&(1<<j))
            answer = min(answer, cost[j][i] + solve(i+1, (mask^(1<<j)), n));
    }

    return dp[i][mask] = answer;
}

int main() {
   fast_io;
   int t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   memset(dp, -1, sizeof dp);
   while(t--)
   {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> cost[i][j];
        }
        cout << solve(0, (1<<n) - 1, n) << '\n';
   }

   return 0;
}

/* 
Problem 10: There are 100 different types of caps each having a unique id from 1 to 100. Also, there are ‘n’ persons each having a collection of a variable number of caps. One day all of these persons decide to go in a party wearing a cap but to look unique they decided that none of them will wear the same type of cap. So, count the total number of arrangements or ways such that none of them is wearing the same type of cap. Constraints: 1 <= n <= 10 Example:

The first line contains the value of n, next n lines contain collections 
of all the n persons.
Input: 
3
5 100 1     // Collection of the first person.
2           // Collection of the second person.
5 100       // Collection of the third person.
Output:
4
Explanation: All valid possible ways are (5, 2, 100),  (100, 2, 5),
            (1, 2, 5) and  (1, 2, 100) 
*/

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<int> capList[101];


int dp[1025][101];


int allmask;


long long int countWaysUtil(int mask, int i)
{

	if (mask == allmask) return 1;


	if (i > 100) return 0;

	if (dp[mask][i] != -1) return dp[mask][i];


	long long int ways = countWaysUtil(mask, i+1);

	int size = capList[i].size();


	for (int j = 0; j < size; j++)
	{

		if (mask & (1 << capList[i][j])) continue;


		else ways += countWaysUtil(mask | (1 << capList[i][j]), i+1);
		ways %= MOD;
	}

	return dp[mask][i] = ways;
}

void countWays(int n)
{
	string temp, str;
	int x;
	getline(cin, str); 
	for (int i=0; i<n; i++)
	{
		getline(cin, str);
		stringstream ss(str);

		while (ss >> temp)
		{
			stringstream s;
			s << temp;
			s >> x;

			capList[x].push_back(i);
		}
	}

	allmask = (1 << n) - 1;

	memset(dp, -1, sizeof dp);

	cout << countWaysUtil(0, 1) << endl;
}

// Driver Program
int main()
{ 
	int n;
	cin >> n;
	countWays(n);
	return 0;
}

/* 
Problem 11: Partition array to K subsets

Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
public:
    int dp[(1<<16)+2];

    bool isKPartitionPossible(int nums[], int n, int k)
    {
        int sum = 0;
        fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
        
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends

/*
Problem 12: Bitmasking and Dynamic Programming | Travelling Salesman Problem in 2-d array
Given a 2D grid of characters representing 
a town where '*' represents the 
houses, '#' represents the blockage, 
'.' represents the vacant street 
area. Currently you are (0, 0) position.

Our task is to determine the minimum distance 
to be moved to visit all the houses and return
to our initial position at (0, 0). You can 
only move to adjacent cells that share exactly
1 edge with the current cell.
The above problem is the well-known Travelling Salesman Problem.
*/
#include <bits/stdc++.h>
using namespace std;

#define INF 99999999
#define MAXR 12
#define MAXC 12
#define MAXMASK 2048
#define MAXHOUSE 12

// stores distance taking source
// as every dirty tile
int dist[MAXR][MAXC][MAXHOUSE];

// memoization for dp states
int dp[MAXHOUSE][MAXMASK];

// stores coordinates for
// dirty tiles
vector<pair<int, int> > dirty;

// Directions
int X[] = { -1, 0, 0, 1 };
int Y[] = { 0, 1, -1, 0 };

char arr[21][21];

// len : number of dirty tiles + 1
// limit : 2 ^ len -1
// r, c : number of rows and columns
int len, limit, r, c;

// Returns true if current position
// is safe to visit
// else returns false
// Time Complexity : O(1)
bool safe(int x, int y)
{
	if (x >= r or y >= c or x < 0 or y < 0)
		return false;
	if (arr[x][y] == '#')
		return false;
	return true;
}

// runs BFS traversal at tile idx
// calculates distance to every cell
// in the grid
// Time Complexity : O(r*c)
void getDist(int idx)
{

	// visited array to track visited cells
	bool vis[21][21];
	memset(vis, false, sizeof(vis));

	// getting current position
	int cx = dirty[idx].first;
	int cy = dirty[idx].second;

	// initializing queue for bfs
	queue<pair<int, int> > pq;
	pq.push({ cx, cy });

	// initializing the dist to max
	// because some cells cannot be visited
	// by taking source cell as idx
	for (int i = 0; i <= r; i++)
		for (int j = 0; j <= c; j++)
			dist[i][j][idx] = INF;

	// base conditions
	vis[cx][cy] = true;
	dist[cx][cy][idx] = 0;

	while (!pq.empty()) {
		auto x = pq.front();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			cx = x.first + X[i];
			cy = x.second + Y[i];
			if (safe(cx, cy)) {
				if (vis[cx][cy])
					continue;
				vis[cx][cy] = true;
				dist[cx][cy][idx]
					= dist[x.first][x.second][idx] + 1;
				pq.push({ cx, cy });
			}
		}
	}
}

// Dynamic Programming state transition recursion
// with memoization. Time Complexity: O(n*n*2 ^ n)
int solve(int idx, int mask)
{
	// goal state
	if (mask == limit)
		return dist[0][0][idx];

	// if already visited state
	if (dp[idx][mask] != -1)
		return dp[idx][mask];

	int ret = INT_MAX;

	// state transition relation
	for (int i = 0; i < len; i++) {
		if ((mask & (1 << i)) == 0) {
			int newMask = mask | (1 << i);
			ret = min(ret,
					solve(i, newMask)
						+ dist[dirty[i].first]
								[dirty[i].second][idx]);
		}
	}

	// adding memoization and returning
	return dp[idx][mask] = ret;
}

void init()
{
	// initializing containers
	memset(dp, -1, sizeof(dp));
	dirty.clear();

	// populating dirty tile positions
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '*')
				dirty.push_back({ i, j });
		}

	// inserting ronot's location at the
	// beginning of the dirty tile
	dirty.insert(dirty.begin(), { 0, 0 });

	len = dirty.size();

	// calculating LIMIT_MASK
	limit = (1 << len) - 1;

	// precalculating distances from all
	// dirty tiles to each cell in the grid
	for (int i = 0; i < len; i++)
		getDist(i);
}

int main(int argc, char const* argv[])
{
	// Test case #1:
	//	 .....*.
	//	 ...#...
	//	 .*.#.*.
	//	 .......

	char A[4][7]
		= { { '.', '.', '.', '.', '.', '*', '.' },
			{ '.', '.', '.', '#', '.', '.', '.' },
			{ '.', '*', '.', '#', '.', '*', '.' },
			{ '.', '.', '.', '.', '.', '.', '.' } };

	r = 4;
	c = 7;

	cout << "The given grid : " << endl;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << A[i][j] << " ";
			arr[i][j] = A[i][j];
		}
		cout << endl;
	}

	// - initialization
	// - precalculations
	init();

	int ans = solve(0, 1);

	cout << "Minimum distance for the given grid : ";
	cout << ans << endl;

	// Test Case #2
	//	 ...#...
	//	 ...#.*.
	//	 ...#...
	//	 .*.#.*.
	//	 ...#...

	char Arr[5][7]
		= { { '.', '.', '.', '#', '.', '.', '.' },
			{ '.', '.', '.', '#', '.', '*', '.' },
			{ '.', '.', '.', '#', '.', '.', '.' },
			{ '.', '*', '.', '#', '.', '*', '.' },
			{ '.', '.', '.', '#', '.', '.', '.' } };

	r = 5;
	c = 7;

	cout << "The given grid : " << endl;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << Arr[i][j] << " ";
			arr[i][j] = Arr[i][j];
		}
		cout << endl;
	}

	// - initialization
	// - precalculations
	init();
	ans = solve(0, 1);
	cout << "Minimum distance for the given grid : ";
	if (ans >= INF)
		cout << "not possible" << endl;
	else
		cout << ans << endl;

	return 0;
}

/*Problem 13: Travelling Salesman Problem 
Find the shortest route that visits each city exactly once, travels the distance between each pair of cities, and then returns to the starting city.
*/
#include <stdio.h>  
#include <limits.h>  
  
#define MAX_N 15 // Maximum number of cities  
  
int n; // Number of cities  
int cost[MAX_N][MAX_N]; // Cost matrix  
int dp[1 << MAX_N][MAX_N]; // Dynamic programming table  
  
int tsp(int mask, int pos) {  
    if (mask == (1 << n) - 1) {  
        return cost[pos][0]; // Return to the starting city  
    }  
  
    if (dp[mask][pos] != -1) {  
        return dp[mask][pos];  
    }  
  
    int ans = INT_MAX;  
    for (int next = 0; next < n; next++) {  
        if ((mask & (1 << next)) == 0) { // If city 'next' is not visited  
            int newCost = cost[pos][next] + tsp(mask | (1 << next), next);  
            ans = min(ans, newCost);  
        }  
    }  
  
    return dp[mask][pos] = ans;  
}  
  
int main() {  
    printf("Enter the number of cities: ");  
    scanf("%d", &n);  
  
    printf("Enter the cost matrix:\n");  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            scanf("%d", &cost[i][j]);  
        }  
    }  
  
    memset(dp, -1, sizeof(dp));  
  
    int minCost = tsp(1, 0); // Start from city 0  
  
    printf("Minimum cost of the TSP: %d\n", minCost);  
  
    return 0;  
}  

/*
Problem 14: Help the king maximize profit
A king possesses vacant houses within his town, arranged in an 
matrix. Each house is currently unoccupied. Within the town, there are introverted and extroverted individuals seeking residence.

When the king allocates a house to an introvert, he gains 360
 rupees; if given to an extrovert, he gains 120
 rupees.

However, for each person residing near an introvert, the king incurs a loss of 90
 rupees, whereas for each person near an extrovert, he gains 60
 rupees.

The objective is to determine the maximum profit achievable by the king. The allocation of accommodation to all individuals is not mandatory; the primary goal is to optimize the king's profit.

A person is called residing near another person if they live in the directly adjacent cells north, east, south, and west of a person's cell.

Input Format:

The one and only line contains 
 integers 
, 
, 
 (no of introverts) and 
 (no of extroverts).

Output Format:

Print one integer - the maximum profit achievable by the king
*/
#include<bits/stdc++.h>
using namespace std;
int dp[25][7][7][128][128];
int dif(int inmask,int exmask,int n,int m,bool introv,int pos){
    int ans=0;
    int row=pos/m;
    int col=pos%m;
    
    int neigh=0;
    int cnt=0;
    if(row>0){
       
        int upPos=m-1;
        if(inmask&(1<<upPos) || exmask&(1<<upPos)){
            if(inmask&(1<<upPos)){
                cnt++;
                neigh-=90;
            }
            else{
                cnt++;
                neigh+=60;
            }
        }
        
    }
    if(col>0){
        
        int leftPos=0;
        if(inmask&(1<<leftPos) || exmask&(1<<leftPos)){
            if(inmask&(1<<leftPos)){
                cnt++;
                neigh-=90;
            }
            else{
                cnt++;
                neigh+=60;
            }
        }
    }
    return ((introv)?-90*cnt:60*cnt)+neigh;
    
}
int rec(int pos,int i,int e,int inmask,int exmask,int n,int m){
    
    int n_inmask=(inmask<<1)&63;
    int n_exmask=(exmask<<1)&63;
    if(pos==(n*m)) return 0;
    
    if(dp[pos][i][e][inmask][exmask]!=-1) return dp[pos][i][e][inmask][exmask];
    int a=rec(pos+1,i,e,n_inmask,n_exmask,n,m);
    //introvert here
    int b=0;
    if(i>0) {
        b=360+rec(pos+1,i-1,e,n_inmask+1,n_exmask,n,m);
        int p=dif(inmask,exmask,n,m,1,pos);
      
        b+=p;
    }
    int c=0;
    //extrovert here
    if(e>0) {
        int p=dif(inmask,exmask,n,m,0,pos);
       
        
        c=120+rec(pos+1,i,e-1,n_inmask,n_exmask+1,n,m)+p;
    }
    return dp[pos][i][e][inmask][exmask]=max({a,b,c});

        
}
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,x,y,0,0,m,n)<<"\n";
}

/*
Problem 15: Arpa and choosing brother free subset
Arpas family consists of 
 men. We can show them with a rooted tree with 
 vertices. Arpa wants to choose 
 of them for playing football but he shouldn't choose someone and his brother too. In short, there should be no direct siblings, both selected for playing football. Print in how many ways he can choose this set modulo 10^9 + 7
.

Input Format

The first line contains two integers, n, k (
).

The second line contains 
 integers 
 (
) -- 
 is the index of the parent of 
-th person.

Output Format

Print in how many ways he can choose this set modulo 
.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxk = 1e2 + 1, maxn = 1e5 + 17, mod = 1e9 + 7;
int n, k, a[maxn], dp[maxk], old[maxk];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	a[0] = 1;
	for(int i = 2; i <= n; i++){
		int p;
		cin >> p;
		a[p]++;
	}
	old[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			dp[j] = ((ll) a[i] * (j ? old[j - 1] : 0) + old[j]) % mod;
			if(dp[j] < 0)
				dp[j] += mod;
			if(dp[j] >= mod)
				dp[j] -= mod;
		}
		memcpy(old, dp, sizeof dp);
	}
	cout << dp[k] << '\n';
}

/*
Problem 16: String Matching
Given a string X formed out of single digit numbers from 0 - 9
 , you are given a set of digits S and you need to count total substring of string X that contains all the digits in the set S.
Input
First line contains a string as input. Next line contains a number n as input denoting size of set S. Next line contains n space separated integers that denote the distinct integers in the set S.
Output
In the output you have to give total count of substrings of the string X such that they contain all the digits in the set S
Constraints
*/

#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define reset(a) memset(a,0,sizeof(a))
#define rep(i,j,k) for(i=j;i<=k;++i)
#define per(i,j,k) for(i=j;i>=k;--i)
#define print(a,start,end) for(i=start;i<=end;++i) cout<<a[i];
#define endl "\n"
#define inf 100000000000000
LL pow(LL a,LL b,LL m){LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
LL dp[1001][1024];
//dp[i][j] total sequences ending at i that have bitmask of j as the set forming elements
int main()
	{
		ios_base::sync_with_stdio(0);
		int n,MASK=0,i,j;
		string x;
		
		int s[14];
		cin>>x;
		x = ' ' + x;
		cin>>n;
		rep(i,1,n)
			{
				cin>>s[i];
				MASK|=(1<<s[i]);
			}
		dp[0][0] = 1;
		rep(i,1,x.length()-1)
			{
				//cout<<x[i]<<endl;
				dp[i][0] = 1;
				for(j=0;j<=1023;j++)
					{
						dp[i][j|(1<<(x[i]-'0'))] += dp[i-1][j];
					}
			}
		LL ans = 0;
		rep(i,1,x.length()-1){
		rep(j,0,1023)
			{
				if((j&MASK)==MASK)
					{
						ans = ans + dp[i][j];
					}
			}
		}
		cout<<ans;
	}

/*
Problem 17: Micro and Lucky Tree
Micro purchased a tree having N nodes numbered from 1 to N. It is rooted at node numbered 1. But unfortunately that tree turned out to be bad luck. After he purchased that tree, he lost his job and girlfriend. So he went to his astrologer friend Mike for help.

Mike told him to assign a value in the range 1 to M (inclusive) to each node making sure that luck factor of all leaf nodes is 1. Luck factor of a leaf node v is defined as gcd
 of values of all nodes lying in path from root to v (inclusive). Now Micro wants to know how many ways are there to make his tree lucky. That's where Mike failed, so he asked for your help.

Input:
First line consists of a single integer denoting N and M.
Each of the following N-1
 lines consists of two space separated integers X and Y denoting there is an edge between nodes numbered X and Y.

Output:
Print the number of ways to make the tree lucky. Since the answer can be large, print it modulo 
.

Constraints:
*/

#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n, m;
ll dp[300][100100];
int bit[300]={0};
vector<int> v[100100];
ll dfs(int x, int par, int mask){
	if(dp[mask][x] != -1)return dp[mask][x];
	ll ret = 0;
	for(int i=1; i<=m; i++){
		int flag = 1;
		ll p = 1;
		for(int j=0; j < v[x].size(); j++){
			if(v[x][j] == par)continue;
			p = (p*dfs(v[x][j], x, mask & bit[i]))%MOD;
			flag = 0;
		}
		if(flag){
			if((mask&bit[i]) == 0)ret++;
		}
		else{
			ret = (ret+p)%MOD;
		}
	}
	return dp[mask][x]=ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin>>n>>m;
	for(int i=1; i<n; i++){
		ll x, y; cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	int arr[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	for(int i=1; i<=m; i++){
		for(int j=0; j<8; j++)
			if(i%arr[j] == 0)
				bit[i]|=(1<<j);
	}

	cout<<dfs(1, -1, 255)<<endl;

	return 0;
}

/*
Problem 18: The Ghost Type
Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.

Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N.

A permutation is called special if it satisfies following condition:

If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.

Help Gengar in finding the number of such permutations.

Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.

Output format:
Output the total number of special permutations of length N.

Constraints:
1 ≤ N ≤ 20
*/

// There is nothing in a caterpillar that tells you its going to be a butterfly --------------------- !
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define ll  long long int
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back
vector<int>submask[22];
bool vis[1<<22];
ll dp[1<<22];
int N;
ll rec(int mask){
    if(mask==(1<<(N+1))-2) return 1;
    if(vis[mask]) return dp[mask];
    vis[mask] = 1;
    ll &ret = dp[mask];
    ret=0;
    int x;
    for(int i=1;i<=N;i++){
        if(!(mask&(1<<i))){
            bool ok = 1;
            rep(j,submask[i].size()){
                x = submask[i][j];
                if(!(mask&(1 << x ))) ok=0;
            }
            if(ok){
                ret += rec(mask|(1<<i));
            }
        }
    }
    return ret;
}
int main(){
    freopen("input-19.txt","r",stdin);
    freopen("output-19.txt","w",stdout);
    for(int i=1;i<=20;i++){
        for(int j=i-1;j>=1;j--){
            if( (i&j)==j ) submask[i].pb(j);
        }
    }
    cin >> N;
    cout<<rec(0);
}

/*
Problem 19: Akatsuki vs Leaf
Akatsuki is planning to attack the Leaf Village to capture Naruto. The Hokage ( Head of the Village ), came to know about the plan and also the number of members, N, in Akatsuki who are going to attack. So, Hokage planned an ambush.

enter image description here

Hokage selected a team of N members ( one for each Akatsuki member ) and named it Leaf. Each member of Leaf can attack exactly one Akatsuki member and an Akatsuki member is NOT attacked by more than one Leaf member. In the ambush there will be N fights ( one of each N members of Leaf and N members of Akatsuki ). You are the leader of Leaf. You know the positions ( x-coordinates and y-coordinates ) of all the Akatsuki members and Leaf members. Your task is to assign each member of Leaf to exactly one member of Akatsuki team such that the sum of the distance between them is minimum. Distance between two points (x1, y1)
 and (x2, y2)
 will be equal to mod(x1-x2) + mod(y1-y2) where mod(x) is the absolute value of x.
.

Input:
First line contains one integer N, number of Akatsuki members who are going to attack the village.
Next N lines will contain two integers each, X and Y, x-coordinate and y-coordinate of the Akatsuki members.
Next N lines will contain two integers each, X and Y, x-coordinate and y-coordinate of the Leaf members.

Output:
Print the required minimum sum of the distance.
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;
const int MAX = (1 << 20) + 5;
const long long INF = (1e9 + 5);
int dist[25][25], memo[MAX][25], n, target, xa[25], ya[25], xb[25], yb[25];

int matching(int bitmaska, int maskb)
{
    int ans = INF, pa, pb;
    if(memo[bitmaska][maskb] >= 0)
        return memo[bitmaska][maskb];
    if(bitmaska == target and maskb == n)
        return (memo[bitmaska][maskb] = 0);

    for(pa = 0;pa < n;++pa)
    {
        if(!(bitmaska & (1 << pa)))
            ans = min(ans, dist[pa][maskb] + matching(bitmaska | (1 << pa), maskb + 1));
    }

    return (memo[bitmaska][maskb] = ans);
}

int main(int argc, char *argv[])
{
    if(argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if(argc == 3)
        freopen(argv[2], "w", stdout);
    int x, y;
    scanf("%d", &n);
    assert(1 <= n and n <= 20);
    for(int i = 0;i < n;++i)
    {
        scanf("%d %d", &x, &y);
        assert(-1000000 <= x and x <= 1000000);
        assert(-1000000 <= y and y <= 1000000);
        xa[i] = x, ya[i] = y;
    }

    for(int i = 0;i < n;++i)
    {
        scanf("%d %d", &x, &y);
        assert(-1000000 <= x and x <= 1000000);
        assert(-1000000 <= y and y <= 1000000);
        xb[i] = x, yb[i] = y;
    }

    for(int i = 0;i < n;++i)
        for(int j = 0;j < n;++j)
            dist[i][j] = (abs(xa[i] - xb[j]) + abs(ya[i] - yb[j]));

    memset(memo, -1, sizeof(memo));

    target = (1 << n) - 1;

    printf("%d\n", matching(0, 0));

    return 0;
}

/*
Problem 20: 

You are given a list A of N integers. Here, N is an even number. These integers must be distributed into N/2 pairs and the power of each of the pairs is added.

The power of a pair P(i, j) consisting of the i-th and j-th number is defined as bitwise XOR of the two numbers A[i] and A[j], that is A[i] ^ A[j] where 1 < i < N, 1 < j < N and i != j.

Write a program to determine the minimum and the maximum possible sum of the N/2 pairs.

Again this problem has the following characteristics:

Assuming that the array A is the list of N integers, we need to assign each integer to only a single pair.
Depending in which order we assign the integers to the pairs, the total sum would change.
We need to evaluate all possible pairings. The number of possible pairings is N!/((N/2)!*2^(N/2)). Which is still exponential in N.
Brute force solution is to go through all possible assignment of integers to the pairs which can be easily accomplished using recursion. But will skip that as it is trivial.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int count_set_bits(int n) {
    int count = 0;
    while (n) {
        n &= (n-1);
        count++;
    }
    return count;
}

vector<int> xor_assignment(vector<int> arr) {
    int N = arr.size();
    int size = pow(2, N);
    vector<int> f(size, INT_MAX);
    vector<int> g(size, INT_MIN);
    
    f[0] = 0;
    g[0] = 0;
    
    for (int k = 1; k < size; ++k) {
        int m = count_set_bits(k);
        
        if (m % 2 == 0) {
            for (int i = 0; i < N; ++i) {
                for (int j = i+1; j < N; ++j) {
                    if (k & (1 << i) && k & (1 << j)) {
                        int h = k & ~(1 << i) & ~(1 << j);
                        f[k] = min(f[k], f[h] + (arr[i] ^ arr[j]));
                        g[k] = max(g[k], g[h] + (arr[i] ^ arr[j]));
                    }
                }
            }
        }
    }
    return {f[size-1], g[size-1]};
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<int> result = xor_assignment(arr);
    cout << "Minimum sum: " << result[0] << endl;
    cout << "Maximum sum: " << result[1] << endl;
    return 0;
}

/*
Problem 21:

There are n people and 40 types of hats labeled from 1 to 40.

Given a list of list of integers hats, where hats[i] is a list of all hats preferred by the i-th person.

Return the number of ways that the n people wear different hats to each other.

This is similar to the order assignment problem, only difference is that the number of executives may not be equal to the number of orders (which is more realistic). Also the problem asks for number of ways of assignment instead of finding minimum cost.

The problem satisfies the following traits:

If we assume that the array A is the list of people then we must assign a single hat to each people depending on their preferences.
Depending on which hat is assigned to which people, we would have different number of ways of assigning hats.
Total number of assignments is exponential in N (number of people). Then the number of possibilities is approximately ‘M chooses N’ where M is the number of hats.
For a subset of K people, the number of ways of assigning hats numbered 1 to H can be found by assuming that the i-th person selects the H-th hat (if he has in its preference) and the remaining K-1 people selects from hats numbered 1 to H-1.
The problem can be solved using recursion. But that would be trivial.

Instead we show a python solution using bitmasking + DP approach:
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int hats_assignment(vector<vector<int>>& hats) {
    vector<set<int>> hat_preferences;
    for (auto& person : hats) {
        set<int> person_hats(person.begin(), person.end());
        hat_preferences.push_back(person_hats);
    }

    vector<vector<int>> f(1 << hats.size(), vector<int>(41, 0));
    
    for (int k = 0; k < (1 << hats.size()); ++k) {
        for (int h = 1; h <= 40; ++h) {
            if (k == 0) {
                f[k][h] = 0;
            } else {
                f[k][h] = (h > 1) ? f[k][h - 1] : 0;
                
                for (int i = 0; i < hats.size(); ++i) {
                    if (k & (1 << i)) {
                        if (hat_preferences[i].find(h) != hat_preferences[i].end()) {
                            f[k][h] += ((k & (k - 1)) != 0) ? f[k & ~(1 << i)][h - 1] : 1;
                        }
                    }
                }
            }
        }
    }
    
    return f[(1 << hats.size()) - 1][40] % (int)(1e9 + 7);
}

int main() {
    vector<vector<int>> hats = {{1, 2, 3}, {2, 3, 5}, {1, 5, 7}, {2, 3}};
    int result = hats_assignment(hats);
    cout << "Number of ways to assign hats: " << result << endl;
    return 0;
}

/*
Problem 22: 

You are given a bunch of sticks. For each stick, its two ends are labelled with two numbers (1–6, possibly same).

You can connect two stick A and B, if and only if one of numbers of stick A is the same as one of the numbers of stick B. For example, a stick with [1,5] can be connected with a stick with [1,4] by connecting the two ends labelled as 1. In this case, these two sticks will become one with longer length, and its two ends now becomes [4,5]. Assume for each given stick, its length is 1.

Return the length of longest stick that can be formed using the given sticks.

The problem is similar to the Hamiltonian path problem seen above as in we need to do DFS to find the solution, only difference is that instead of finding a Hamiltonian path, we need to find the longest path.

This can be done in brute force way by recursion (DFS) but that would not be interesting enough !!! By now we must have got the clue how this problem can be solved using bitmasking and DP.

Below is the python code:
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxLen(int n, vector<vector<int>>& sticks, int face = 0) {
    vector<vector<pair<int, int>>> f(1 << n, vector<pair<int, int>>(n, {-1, -1}));
    int out = 1;
    
    for (int k = 0; k < (1 << n); ++k) {
        for (int i = 0; i < n; ++i) {
            if (k & (1 << i)) {
                if ((k & (k-1)) == 0) {
                    f[k][i] = {1, sticks[i][face]};
                } else {
                    int max_len = -1;
                    int max_len_end = -1;
                    for (int j = 0; j < n; ++j) {
                        if (i != j && (k & (1 << j))) {
                            auto [p, q] = f[k & ~(1 << i)][j];
                            if (sticks[i][0] == q || sticks[i][1] == q) {
                                if (p+1 > max_len) {
                                    max_len = p+1;
                                    max_len_end = (sticks[i][0] == q) ? sticks[i][1] : sticks[i][0];
                                }
                            }
                        }
                    }
                    f[k][i] = {max_len, max_len_end};
                }
                out = max(out, f[k][i].first);
            }
        }
    }
    return out;
}

int joinSticks(vector<vector<int>>& sticks) {
    int n = sticks.size();
    int a = getMaxLen(n, sticks, 0);
    int b = getMaxLen(n, sticks, 1);
    return max(a, b);
}

int main() {
    vector<vector<int>> sticks = {{1, 2}, {1, 3}, {2, 4}, {3, 5}, {3, 6}, {5, 6}};
    cout << "Length of longest stick that can be formed: " << joinSticks(sticks) << endl;
    return 0;
}



