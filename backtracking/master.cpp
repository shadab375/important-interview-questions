1) A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

Constraints:

1 <= s.length <= 20
s consists of digits only.

class Solution {
public:
    int n;
    vector<string> result;
    
    bool isValid(string str) {
        if(str[0] == '0')
            return false;
        
        int val = stoi(str);
        
        return val <= 255;
    }
    
    void solve(string& s, int idx, int part, string curr) {
        if(idx == n && part == 4) {
            result.push_back(curr.substr(0, curr.length()-1));
            return;
        }
        
        if(idx+1 <= n)
            solve(s, idx+1, part+1, curr + s.substr(idx, 1) + ".");
        
        if(idx+2 <= n && isValid(s.substr(idx, 2))) {
            solve(s, idx+2, part+1, curr + s.substr(idx, 2) + ".");
        }
        
        if(idx+3 <= n && isValid(s.substr(idx, 3))) {
            solve(s, idx+3, part+1, curr + s.substr(idx, 3) + ".");
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        
        n = s.length();
        
        if(n > 12)
          return result;
      
        int part = 0;
        string curr = "";
        
        solve(s, 0, part, curr);
        return result;
        
    }
};

2) Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
Example 2:

Input: n = 1
Output: 1
class Solution {
public:
    void solve(vector<int>& nums, int n, int& ans, int cur_num){
        //base case
        if(cur_num >= n+1){
            ans++;
            return;
        }

        //recursive relation
        for(int j=1; j<=n; j++){
            if(nums[j] == 0 && (cur_num % j == 0 || j % cur_num == 0)){
                nums[j] = cur_num;
                solve(nums, n, ans, cur_num+1);
                //backtracking
                nums[j] = 0;
            }
        }
    }


    int countArrangement(int n) {
        vector<int> nums(n+1);
        int ans = 0, ind = 1;
        solve(nums, n, ans, ind);
        return ans;
    }
};

3) Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i = 0 ;i<board.size();++i){
            for(int j = 0 ;j<board[0].size();++j){
                if(board[i][j]=='.'){
                    for(char k = '1' ;k<='9';k++){
                        if(isvalid(i,j,k,board)){
                                 board[i][j]=k;
                            if(solve(board)){
                               return true;
                            }
                        
                        else{
                            board[i][j] = '.' ;

                        }
                        }
                    }
                    return false;
                }
            }
        }return true;
    }
    bool isvalid(int r,int c ,char digit,vector<vector<char>>&board){
        for(int i = 0 ;i<9;i++){
            if(board[r][i]==digit){
                return false;
            }
            if(board[i][c]==digit){
                return false;
            }
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==digit){
                return false;
            }
        }return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};

4) Knights Tour
Problem Statement:
Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules of chess knight must visit each square exactly once. Print the order of each cell in which they are visited.
// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[]);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
    int sol[N][N];

    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    /* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // Since the Knight is initially at the first block
    sol[0][0] = 0;

    /* Start from 0,0 and explore all tours using
    solveKTUtil() */
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solution does not exist";
        return 0;
    }
    else
        printSolution(sol);

    return 1;
}

/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;

    /* Try all next moves from
    the current coordinate x, y */
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove)
                == 1)
                return 1;
            else
               
               // backtracking
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

// Driver Code
int main()
{
      // Function Call
    solveKT();
    return 0;
}

// This code is contributed by ShubhamCoder


4) ii) Knights tour wardanoff's heuristics
// C++ program to for Knight's tour problem using
// Warnsdorff's algorithm
#include <bits/stdc++.h>
#define N 8

// Move pattern on basis of the change of
// x coordinates and y coordinates respectively
static int cx[N] = {1,1,2,2,-1,-1,-2,-2};
static int cy[N] = {2,-2,1,-1,2,-2,1,-1};

// function restricts the knight to remain within
// the 8x8 chessboard
bool limits(int x, int y)
{
	return ((x >= 0 && y >= 0) && (x < N && y < N));
}

/* Checks whether a square is valid and empty or not */
bool isempty(int a[], int x, int y)
{
	return (limits(x, y)) && (a[y*N+x] < 0);
}

/* Returns the number of empty squares adjacent
to (x, y) */
int getDegree(int a[], int x, int y)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
		if (isempty(a, (x + cx[i]), (y + cy[i])))
			count++;

	return count;
}

// Picks next point using Warnsdorff's heuristic.
// Returns false if it is not possible to pick
// next point.
bool nextMove(int a[], int *x, int *y)
{
	int min_deg_idx = -1, c, min_deg = (N+1), nx, ny;

	// Try all N adjacent of (*x, *y) starting
	// from a random adjacent. Find the adjacent
	// with minimum degree.
	int start = rand()%N;
	for (int count = 0; count < N; ++count)
	{
		int i = (start + count)%N;
		nx = *x + cx[i];
		ny = *y + cy[i];
		if ((isempty(a, nx, ny)) &&
		(c = getDegree(a, nx, ny)) < min_deg)
		{
			min_deg_idx = i;
			min_deg = c;
		}
	}

	// IF we could not find a next cell
	if (min_deg_idx == -1)
		return false;

	// Store coordinates of next point
	nx = *x + cx[min_deg_idx];
	ny = *y + cy[min_deg_idx];

	// Mark next move
	a[ny*N + nx] = a[(*y)*N + (*x)]+1;

	// Update next point
	*x = nx;
	*y = ny;

	return true;
}

/* displays the chessboard with all the
legal knight's moves */
void print(int a[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			printf("%d\t",a[j*N+i]);
		printf("\n");
	}
}

/* checks its neighbouring squares */
/* If the knight ends on a square that is one
knight's move from the beginning square,
then tour is closed */
bool neighbour(int x, int y, int xx, int yy)
{
	for (int i = 0; i < N; ++i)
		if (((x+cx[i]) == xx)&&((y + cy[i]) == yy))
			return true;

	return false;
}

/* Generates the legal moves using warnsdorff's
heuristics. Returns false if not possible */
bool findClosedTour()
{
	// Filling up the chessboard matrix with -1's
	int a[N*N];
	for (int i = 0; i< N*N; ++i)
		a[i] = -1;

	// Random initial position
	int sx = rand()%N;
	int sy = rand()%N;

	// Current points are same as initial points
	int x = sx, y = sy;
	a[y*N+x] = 1; // Mark first move.

	// Keep picking next points using
	// Warnsdorff's heuristic
	for (int i = 0; i < N*N-1; ++i)
		if (nextMove(a, &x, &y) == 0)
			return false;

	// Check if tour is closed (Can end
	// at starting point)
	if (!neighbour(x, y, sx, sy))
		return false;

	print(a);
	return true;
}

// Driver code
int main()
{
	// To make sure that different random
	// initial positions are picked.
	srand(time(NULL));

	// While we don't get a solution
	while (!findClosedTour())
	{
	;
	}

	return 0;
}


5) Remove Invalid Parantehsis
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]

class Solution {
private:
unordered_map<string,int> dp;
int Remove_Invalid_Parentheses(string s,int cnt,set<string>& st){
    if(cnt==0){
        int minr = solve(s);
        if(minr==0){
            st.insert(s);
            return 1;
        }
        return 0;
    }
    if(dp.find(s)!=dp.end())return dp[s];
    for(int i=0;i<s.size();i++){
        if(s[i]==')'||s[i]=='('){
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            dp[left+right] = Remove_Invalid_Parentheses(left+right,cnt-1,st);
        }
    }
    return dp[s];
}
int solve(string s){
    int cnt = 0,n=s.size();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push('(');
        }else if(s[i]==')') {
            if(!st.empty()&&st.top()=='(')st.pop();
            else st.push(s[i]);
        }
    }
    return st.size();
}

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> v;
        int cnt = solve(s);
        set<string> st;
        Remove_Invalid_Parentheses(s,cnt,st);
        while(!st.empty()){
            v.push_back(*st.begin());
            st.erase(st.begin());
        }
        cout<<cnt<<endl;
        return v;
    }
};

6) Hamiltonian Path in a graph G is a path that visits every vertex of G exactly once and Hamiltonian Path doesn’t have to return to the starting vertex. It’s an open path.
Problems Statement: Given an undirected graph, the task is to determine whether the graph contains a Hamiltonian cycle or not. If it contains, then prints the path.

Input: graph[][] = {{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 1},{0, 1, 1, 1, 0}}


Input graph[][]

Output: {0, 1, 2, 4, 3, 0}.

/* C++ program for solution of Hamiltonian 
Cycle problem using backtracking */
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph 
#define V 5 

void printSolution(int path[]); 

/* A utility function to check if 
the vertex v can be added at index 'pos' 
in the Hamiltonian Cycle constructed 
so far (stored in 'path[]') */
bool isSafe(int v, bool graph[V][V], 
			int path[], int pos) 
{ 
	/* Check if this vertex is an adjacent 
	vertex of the previously added vertex. */
	if (graph [path[pos - 1]][ v ] == 0) 
		return false; 

	/* Check if the vertex has already been included. 
	This step can be optimized by creating
	an array of size V */
	for (int i = 0; i < pos; i++) 
		if (path[i] == v) 
			return false; 

	return true; 
} 

/* A recursive utility function 
to solve hamiltonian cycle problem */
bool hamCycleUtil(bool graph[V][V], 
				int path[], int pos) 
{ 
	/* base case: If all vertices are 
	included in Hamiltonian Cycle */
	if (pos == V) 
	{ 
		// And if there is an edge from the 
		// last included vertex to the first vertex 
		if (graph[path[pos - 1]][path[0]] == 1) 
			return true; 
		else
			return false; 
	} 

	// Try different vertices as a next candidate 
	// in Hamiltonian Cycle. We don't try for 0 as 
	// we included 0 as starting point in hamCycle() 
	for (int v = 1; v < V; v++) 
	{ 
		/* Check if this vertex can be added 
		// to Hamiltonian Cycle */
		if (isSafe(v, graph, path, pos)) 
		{ 
			path[pos] = v; 

			/* recur to construct rest of the path */
			if (hamCycleUtil (graph, path, pos + 1) == true) 
				return true; 

			/* If adding vertex v doesn't lead to a solution, 
			then remove it */
			path[pos] = -1; 
		} 
	} 

	/* If no vertex can be added to 
	Hamiltonian Cycle constructed so far, 
	then return false */
	return false; 
} 

/* This function solves the Hamiltonian Cycle problem 
using Backtracking. It mainly uses hamCycleUtil() to 
solve the problem. It returns false if there is no 
Hamiltonian Cycle possible, otherwise return true 
and prints the path. Please note that there may be 
more than one solutions, this function prints one 
of the feasible solutions. */
bool hamCycle(bool graph[V][V]) 
{ 
	int *path = new int[V]; 
	for (int i = 0; i < V; i++) 
		path[i] = -1; 

	/* Let us put vertex 0 as the first vertex in the path.
	If there is a Hamiltonian Cycle, then the path can be 
	started from any point of the cycle as the graph is undirected */
	path[0] = 0; 
	if (hamCycleUtil(graph, path, 1) == false ) 
	{ 
		cout << "\nSolution does not exist"; 
		return false; 
	} 

	printSolution(path); 
	return true; 
} 

/* A utility function to print solution */
void printSolution(int path[]) 
{ 
	cout << "Solution Exists:"
			" Following is one Hamiltonian Cycle \n"; 
	for (int i = 0; i < V; i++) 
		cout << path[i] << " "; 

	// Let us print the first vertex again
	// to show the complete cycle 
	cout << path[0] << " "; 
	cout << endl;
} 

// Driver Code 
int main() 
{ 
	/* Let us create the following graph 
		(0)--(1)--(2) 
		|	 / \ | 
		| /	 \ | 
		| /	 \ | 
		(3)-------(4) */
	bool graph1[V][V] = {{0, 1, 0, 1, 0}, 
						{1, 0, 1, 1, 1}, 
						{0, 1, 0, 0, 1}, 
						{1, 1, 0, 0, 1}, 
						{0, 1, 1, 1, 0}}; 
	
	// Print the solution 
	hamCycle(graph1); 
	
	/* Let us create the following graph 
		(0)--(1)--(2) 
		|	 / \ | 
		| /	 \ | 
		| /	 \ | 
		(3)	 (4) */
	bool graph2[V][V] = {{0, 1, 0, 1, 0}, 
						{1, 0, 1, 1, 1}, 
						{0, 1, 0, 0, 1}, 
						{1, 1, 0, 0, 0}, 
						{0, 1, 1, 0, 0}}; 

	// Print the solution 
	hamCycle(graph2); 

	return 0; 
} 

// This is code is contributed by rathbhupendra

7) Find if there is a path of more than k length from a source
Last Updated : 10 Jul, 2023
Given a graph, a source vertex in the graph and a number k, find if there is a simple path (without any cycle) starting from given source and ending at any other vertex such that the distance from source to that vertex is atleast ‘k’ length.

// Program to find if there is a simple path with
// weight more than k
#include<bits/stdc++.h>
using namespace std;

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a dipathted graph using
// adjacency list representation
class Graph
{
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list< pair<int, int> > *adj;
	bool pathMoreThanKUtil(int src, int k, vector<bool> &path);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);
	bool pathMoreThanK(int src, int k);
};

// Returns true if graph has path more than k length
bool Graph::pathMoreThanK(int src, int k)
{
	// Create a path array with nothing included
	// in path
	vector<bool> path(V, false);

	// Add source vertex to path
	path[src] = 1;

	return pathMoreThanKUtil(src, k, path);
}

// Prints shortest paths from src to all other vertices
bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path)
{
	// If k is 0 or negative, return true;
	if (k <= 0)
		return true;

	// Get all adjacent vertices of source vertex src and
	// recursively explore all paths from src.
	list<iPair>::iterator i;
	for (i = adj[src].begin(); i != adj[src].end(); ++i)
	{
		// Get adjacent vertex and weight of edge
		int v = (*i).first;
		int w = (*i).second;

		// If vertex v is already there in path, then
		// there is a cycle (we ignore this edge)
		if (path[v] == true)
			continue;

		// If weight of is more than k, return true
		if (w >= k)
			return true;

		// Else add this vertex to path
		path[v] = true;

		// If this adjacent can provide a path longer
		// than k, return true.
		if (pathMoreThanKUtil(v, k-w, path))
			return true;

		// Backtrack
		path[v] = false;
	}

	// If no adjacent could produce longer path, return
	// false
	return false;
}

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}

// Utility function to an edge (u, v) of weight w
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Driver program to test methods of graph class
int main()
{
	// create the graph given in above figure
	int V = 9;
	Graph g(V);

	// making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	int src = 0;
	int k = 62;
	g.pathMoreThanK(src, k)? cout << "Yes\n" :
							cout << "No\n";

	k = 60;
	g.pathMoreThanK(src, k)? cout << "Yes\n" :
							cout << "No\n";

	return 0;
}

8) Subset Sum Problem using Backtracking
Last Updated : 04 Dec, 2023
Given a set[] of non-negative integers and a value sum, the task is to print the subset of the given set whose sum is equal to the given sum.

#include <bits/stdc++.h>
using namespace std;

// Print all subsets if there is atleast one subset of set[]
// with sum equal to given sum
bool flag = 0;
void PrintSubsetSum(int i, int n, int set[], int targetSum,
					vector<int>& subset)
{
	// targetSum is zero then there exist a
	// subset.
	if (targetSum == 0) {

		// Prints valid subset
		flag = 1;
		cout << "[ ";
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i] << " ";
		}
		cout << "]";
		return;
	}

	if (i == n) {
		// return if we have reached at the end of the array
		return;
	}

	// Not considering current element
	PrintSubsetSum(i + 1, n, set, targetSum, subset);

	// consider current element if it is less than or equal
	// to targetSum
	if (set[i] <= targetSum) {

		// push the current element in subset
		subset.push_back(set[i]);

		// Recursive call for consider current element
		PrintSubsetSum(i + 1, n, set, targetSum - set[i],
					subset);

		// pop-back element after recursive call to restore
		// subsets original configuration
		subset.pop_back();
	}
}

// Driver code
int main()
{
	// Test case 1
	int set[] = { 1, 2, 1 };
	int sum = 3;
	int n = sizeof(set) / sizeof(set[0]);
	vector<int> subset;
	cout << "Output 1:" << endl;
	PrintSubsetSum(0, n, set, sum, subset);
	cout << endl;
	flag = 0;
	// Test case 2
	int set2[] = { 3, 34, 4, 12, 5, 2 };
	int sum2 = 30;
	int n2 = sizeof(set) / sizeof(set[0]);
	vector<int> subset2;
	cout << "Output 2:" << endl;
	PrintSubsetSum(0, n2, set2, sum2, subset2);
	if (!flag) {
		cout << "There is no such subset";
	}

	return 0;
}
// This code is contributed by Hem Kishan


9) Print all possible paths from top left to bottom right in matrix
Last Updated : 07 Nov, 2023
Given a 2D matrix of dimension m✕n, the task is to print all the possible paths from the top left corner to the bottom right corner in a 2D matrix with the constraints that from each cell you can either move to right or down only.

#include <bits/stdc++.h>
using namespace std;

// To store the matrix dimension
int M, N;

// Function to print the path taken to reach destination
void printPath(vector<int>& path)
{
	for (int i : path) {
		cout << i << ", ";
	}
	cout << endl;
}

// Function to find all possible path in matrix from top
// left cell to bottom right cell
void findPaths(vector<vector<int> >& arr, vector<int>& path,
			int i, int j)
{

	// if the bottom right cell, print the path
	if (i == M - 1 && j == N - 1) {
		path.push_back(arr[i][j]);
		printPath(path);
		path.pop_back();
		return;
	}

	// Boundary cases: In case in we reach out of the matrix
	if (i < 0 && i >= M && j < 0 && j >= N) {
		return;
	}

	// Include the current cell in the path
	path.push_back(arr[i][j]);

	// Move right in the matrix
	if (j + 1 < N) {
		findPaths(arr, path, i, j + 1);
	}

	// Move down in the matrix
	if (i + 1 < M) {
		findPaths(arr, path, i + 1, j);
	}

	// Backtrack: Remove the current cell from the current
	// path
	path.pop_back();
}

// Driver code
int main()
{
	// Input matrix
	vector<vector<int> > arr
		= { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	// To store the path
	vector<int> path;

	// Starting cell `(0, 0)` cell
	int i = 0, j = 0;

	M = arr.size();
	N = arr[0].size();

	// Function call
	findPaths(arr, path, i, j);

	return 0;
}
10) Find shortest safe route in a path with landmines
Last Updated : 22 Dec, 2023
Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), calculate length of the shortest safe route possible from any cell in the first column to any cell in the last column of the matrix. We have to avoid landmines and their four adjacent cells (left, right, above and below) as they are also unsafe. We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.

// C++ program to find shortest safe Route in
// the matrix with landmines
#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

// A function to check if a given cell (x, y)
// can be visited or not
bool isSafe(int mat[R][C], int visited[R][C],
			int x, int y)
{
	if (mat[x][y] == 0 || visited[x][y])
		return false;

	return true;
}

// A function to check if a given cell (x, y) is
// a valid cell or not
bool isValid(int x, int y)
{
	if (x < R && y < C && x >= 0 && y >= 0)
		return true;

	return false;
}

// A function to mark all adjacent cells of
// landmines as unsafe. Landmines are shown with
// number 0
void markUnsafeCells(int mat[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			// if a landmines is found
			if (mat[i][j] == 0)
			{
			// mark all adjacent cells
			for (int k = 0; k < 4; k++)
				if (isValid(i + rowNum[k], j + colNum[k]))
					mat[i + rowNum[k]][j + colNum[k]] = -1;
			}
		}
	}

	// mark all found adjacent cells as unsafe
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (mat[i][j] == -1)
				mat[i][j] = 0;
		}
	}

	// Uncomment below lines to print the path
	/*for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << std::setw(3) << mat[i][j];
		}
		cout << endl;
	}*/
}

// Function to find shortest safe Route in the
// matrix with landmines
// mat[][] - binary input matrix with safe cells marked as 1
// visited[][] - store info about cells already visited in
// current route
// (i, j) are coordinates of the current cell
// min_dist --> stores minimum cost of shortest path so far
// dist --> stores current path cost
void findShortestPathUtil(int mat[R][C], int visited[R][C],
						int i, int j, int &min_dist, int dist)
{
	// if destination is reached
	if (j == C-1)
	{
		// update shortest path found so far
		min_dist = min(dist, min_dist);
		return;
	}

	// if current path cost exceeds minimum so far
	if (dist > min_dist)
		return;

	// include (i, j) in current path
	visited[i][j] = 1;

	// Recurse for all safe adjacent neighbours
	for (int k = 0; k < 4; k++)
	{
		if (isValid(i + rowNum[k], j + colNum[k]) &&
			isSafe(mat, visited, i + rowNum[k], j + colNum[k]))
		{
			findShortestPathUtil(mat, visited, i + rowNum[k],
						j + colNum[k], min_dist, dist + 1);
		}
	}

	// Backtrack
	visited[i][j] = 0;
}

// A wrapper function over findshortestPathUtil()
void findShortestPath(int mat[R][C])
{
	// stores minimum cost of shortest path so far
	int min_dist = INT_MAX;

	// create a boolean matrix to store info about
	// cells already visited in current route
	int visited[R][C];

	// mark adjacent cells of landmines as unsafe
	markUnsafeCells(mat);

	// start from first column and take minimum
	for (int i = 0; i < R; i++)
	{
		// if path is safe from current cell
		if (mat[i][0] == 1)
		{
			// initialize visited to false
			memset(visited, 0, sizeof visited);

			// find shortest route from (i, 0) to any
			// cell of last column (x, C - 1) where
			// 0 <= x < R
			findShortestPathUtil(mat, visited, i, 0,
								min_dist, 0);

			// if min distance is already found
			if(min_dist == C - 1)
				break;
		}
	}

	// if destination can be reached
	if (min_dist != INT_MAX)
		cout << "Length of shortest safe route is "
			<< min_dist;

	else // if the destination is not reachable
		cout << "Destination not reachable from "
			<< "given source";
}

// Driver code
int main()
{
	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};

	// find shortest path
	findShortestPath(mat);

	return 0;
}

11) Given a binary string s, partition the string into one or more substrings such that each substring is beautiful.

A string is beautiful if:

It doesn't contain leading zeros.
It's the binary representation of a number that is a power of 5.
Return the minimum number of substrings in such partition. If it is impossible to partition the string s into beautiful substrings, return -1.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "1011"
Output: 2
Explanation: We can paritition the given string into ["101", "1"].
- The string "101" does not contain leading zeros and is the binary representation of integer 51 = 5.
- The string "1" does not contain leading zeros and is the binary representation of integer 50 = 1.
It can be shown that 2 is the minimum number of beautiful substrings that s can be partitioned into.

class Solution {
public:
    
    // Returns 1 if y is a power of x
    bool isPower(int x, int y) {
        // The only power of 1 is 1 itself
        if (x == 1) return (y == 1);

        // Repeatedly compute power of x
        long int pow = 1;
        while (pow < y) pow *= x;

        // Check if power of x becomes y
        return (pow == y);
    }
    
    bool valid(string s){
        int n=s.length();
        
        int val=0;
        for(int i=0;i<n;i++) val += (s[i]-'0')*(1 << (n-1-i));
        
        return isPower(5,val);
    }
    
    void solve(string s, int c, int &ans){
        if(s.length() == 0){
            ans=min(ans,c);
            return;
        }
        
        for(int i=0;i<s.length();i++){
            string pre=s.substr(0,i+1);
            string suf=s.substr(i+1);
            
            if(pre[0]!='0' && valid(pre)){
                if(suf.length() > 0 && suf[0]=='0') continue;
                solve(suf,c+1,ans);
            }
        }
    }
    
    int minimumBeautifulSubstrings(string s) {
        int ans=s.length()+1;
        
        solve(s,0,ans);
        return (ans == s.length()+1 ? -1:ans);
    }
};

12) Given a positive integer n, return the punishment number of n.

The punishment number of n is defined as the sum of the squares of all integers i such that:

1 <= i <= n
The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.
 

Example 1:

Input: n = 10
Output: 182
Explanation: There are exactly 3 integers i that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0.
Hence, the punishment number of 10 is 1 + 81 + 100 = 182

class Solution {
private:
    bool canPartition(string& s, int startIdx, int target) {
        if(startIdx == s.size() && target == 0) return true;
        if(target < 0) return false;

        int leftNum = 0;
        for(int i = startIdx; i < s.size(); i++) {
            leftNum = (leftNum * 10) + (s[i] - '0');
            if(canPartition(s, i + 1, target - leftNum)) {
                return true;
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for(int num = 1; num <= n; num++) {
            int sq = num * num;
            string sqrStr = to_string(sq);
            if(canPartition(sqrStr, 0, num)) sum += sq;
        }
        return sum;
    }
};

13) You are given a 0-indexed integer array nums representing the score of students in an exam. The teacher would like to form one non-empty group of students with maximal strength, where the strength of a group of students of indices i0, i1, i2, ... , ik is defined as nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​].

Return the maximum strength of a group the teacher can create.

 

Example 1:

Input: nums = [3,-1,-5,2,5,-9]
Output: 1350
Explanation: One way to form a group of maximal strength is to group the students at indices [0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
                 return getMaxStrength(nums, 0, 1, false);
    }

private:
    long long getMaxStrength(vector<int>& nums, int start, long long product, bool nonZeroFlag) {
        if (start == nums.size()) {
            if (!nonZeroFlag) {
                long long maxNegative = INT64_MIN;
                for (int num : nums) {
                    if (num < 0 && num > maxNegative) {
                        maxNegative = num;
                    }
                }
                return maxNegative;
            }
            return product;
        }

        // Check if product becomes zero
        if (product == 0) {
            return 0;
        }

        // Pick the current element and recursively calculate the strength
        long long pick = getMaxStrength(nums, start + 1, product * nums[start], true);

        // Not pick the current element and recursively calculate the strength
        long long notPick = getMaxStrength(nums, start + 1, product, nonZeroFlag);

        // Return the maximum strength between the two choices
        return max(pick, notPick);
    }
};

14) You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].

class Solution {
public:
    
    int helper(vector<int>& nums, vector<int>& dp, int k, int i, int n) {
        if (i == n) return 0;
        
        int take = 0;
        
        int notTake = helper(nums,dp,k,i + 1,n);
        
        if (binary_search(dp.begin(), dp.end(), nums[i] - k) == 0)
        {
            dp.push_back(nums[i]);
            take = 1 + helper(nums,dp,k,i + 1,n);
            dp.pop_back();
        }
    
        return take + notTake;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp;
        
        return helper(nums,dp,k,0,n);
    }
};

15) You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.

class Solution {
public:
    int vis[20] = {};
    vector<int>v ;
    string ans = "";
    
    void solve(int i , int n , string &s) {
        // Base case: If the permutation vector has reached the desired length
        if(v.size() == n + 1) {
            // Check if the constructed permutation satisfies the pattern
            for(int k = 0; k < n; k++) {
                if(s[k] == 'I' and v[k] > v[k + 1]) return; // If "I" and the next digit is not greater
                else if(s[k] == 'D' and v[k] < v[k + 1]) return; // If "D" and the next digit is not smaller
            }
            // If the constructed permutation satisfies the pattern, convert it to a string
            for(int k: v) ans += char(k + '0');
            return;
        }
        // Recursive step: Try adding each digit from 1 to n+1 to the permutation
        for(int j = 1; j <= n + 1 ; j++) {
            // Check if the digit has not been visited yet
            if(vis[j] == 0 and !ans.size()) {
                // Check if adding the current digit violates the pattern
                if(v.size() > 0 and v.size() < n and s[v.size() - 1] == 'I' and v.back() > j) break;
                if(v.size() > 0 and v.size() < n and s[v.size() - 1] == 'D' and v.back() < j) break;

                // Add the current digit to the permutation
                v.emplace_back(j);
                vis[j] = 1;
                // Recur with the updated permutation
                solve(j , n , s);
                // Backtrack: Remove the last added digit and mark it as unvisited
                v.pop_back();
                vis[j] = 0;
            }
        }
    }
    
    string smallestNumber(string pattern) {
        // Start the recursive function with an initial index of 0
        solve(0 , pattern.size() , pattern);
        // Return the constructed smallest number
        return ans;
    }
};

16) Alice and Bob are opponents in an archery competition. The competition has set the following rules:

Alice first shoots numArrows arrows and then Bob shoots numArrows arrows.
The points are then calculated as follows:
The target has integer scoring sections ranging from 0 to 11 inclusive.
For each section of the target with score k (in between 0 to 11), say Alice and Bob have shot ak and bk arrows on that section respectively. If ak >= bk, then Alice takes k points. If ak < bk, then Bob takes k points.
However, if ak == bk == 0, then nobody takes k points.
For example, if Alice and Bob both shot 2 arrows on the section with score 11, then Alice takes 11 points. On the other hand, if Alice shot 0 arrows on the section with score 11 and Bob shot 2 arrows on that same section, then Bob takes 11 points.

You are given the integer numArrows and an integer array aliceArrows of size 12, which represents the number of arrows Alice shot on each scoring section from 0 to 11. Now, Bob wants to maximize the total number of points he can obtain.

Return the array bobArrows which represents the number of arrows Bob shot on each scoring section from 0 to 11. The sum of the values in bobArrows should equal numArrows.

If there are multiple ways for Bob to earn the maximum total points, return any one of them.

 

Example 1:


Input: numArrows = 9, aliceArrows = [1,1,0,1,0,0,2,1,0,1,2,0]
Output: [0,0,0,0,1,1,0,0,1,2,3,1]
Explanation: The table above shows how the competition is scored. 
Bob earns a total point of 4 + 5 + 8 + 9 + 10 + 11 = 47.
It can be shown that Bob cannot obtain a score higher than 47 points.

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>v;
        int maxi=0;
        for(int i=0; i<(1<<12); i++){
            int n=numArrows, cnt=0;
            vector<int>temp(12, 0);
            for(int j=11; j>=0; j--){
                if(i&(1<<j)){
                    if(n>aliceArrows[j]){
                        n-=(aliceArrows[j]+1);
                        temp[j]=(aliceArrows[j]+1);
                    }
                }
            }
            for(int j=0; j<12; j++){
                if(i&(1<<j)){
                    temp[j]+=n;
                    break;
                }
            }
            for(int j=0; j<12; j++){
                if(temp[j]>aliceArrows[j]){cnt+=j;}
            }
            if(cnt>maxi){
                maxi=cnt;
                v=temp;
            }
        }
        return v;
    }
};

17) You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.

For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum): (12), (2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
Return a list of integers that represent a valid split containing a maximum number of integers. If no valid split exists for finalSum, return an empty list. You may return the integers in any order.

 

Example 1:

Input: finalSum = 12
Output: [2,4,6]
Explanation: The following are valid splits: (12), (2 + 10), (2 + 4 + 6), and (4 + 8).
(2 + 4 + 6) has the maximum number of integers, which is 3. Thus, we return [2,4,6].
Note that [2,6,4], [6,2,4], etc. are also accepted.
Example 2:

Input: finalSum = 7
Output: []
Explanation: There are no valid splits for the given finalSum.
Thus, we return an empty array.

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        long long lastEven = 0;
        if (finalSum%2) return {};
        while (finalSum!=0){
		// start off with the lowest even number
            lastEven+=2;
            if (finalSum-lastEven <=lastEven){
			// if the final sum is smaller than the current even number, that means the remainder will only be the taken numbers
                vector<long long> result;
                for (int i=2; i<lastEven; i+=2){
                    result.push_back(i);
                }
                result.push_back(finalSum);
                return result;
            }else{
                finalSum-=lastEven;
            }
        }
        return {};
    }
};

18) There are two types of persons:

The good person: The person who always tells the truth.
The bad person: The person who might tell the truth and might lie.
You are given a 0-indexed 2D integer array statements of size n x n that represents the statements made by n people about each other. More specifically, statements[i][j] could be one of the following:

0 which represents a statement made by person i that person j is a bad person.
1 which represents a statement made by person i that person j is a good person.
2 represents that no statement is made by person i about person j.
Additionally, no person ever makes a statement about themselves. Formally, we have that statements[i][i] = 2 for all 0 <= i < n.

Return the maximum number of people who can be good based on the statements made by the n people.

 

Example 1:


Input: statements = [[2,1,2],[1,2,2],[2,0,2]]
Output: 2
Explanation: Each person makes a single statement.
- Person 0 states that person 1 is good.
- Person 1 states that person 0 is good.
- Person 2 states that person 1 is bad.
Let's take person 2 as the key.
- Assuming that person 2 is a good person:
    - Based on the statement made by person 2, person 1 is a bad person.
    - Now we know for sure that person 1 is bad and person 2 is good.
    - Based on the statement made by person 1, and since person 1 is bad, they could be:
        - telling the truth. There will be a contradiction in this case and this assumption is invalid.
        - lying. In this case, person 0 is also a bad person and lied in their statement.
    - Following that person 2 is a good person, there will be only one good person in the group.
- Assuming that person 2 is a bad person:
    - Based on the statement made by person 2, and since person 2 is bad, they could be:
        - telling the truth. Following this scenario, person 0 and 1 are both bad as explained before.
            - Following that person 2 is bad but told the truth, there will be no good persons in the group.
        - lying. In this case person 1 is a good person.
            - Since person 1 is a good person, person 0 is also a good person.
            - Following that person 2 is bad and lied, there will be two good persons in the group.
We can see that at most 2 persons are good in the best case, so we return 2.
Note that there is more than one way to arrive at this conclusion.'

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans=0;
        for(int i=1; i<(1<<statements.size()); i++){
            int chk=1;
            for(int j=0; j<statements.size(); j++){
                if(!(i&(1<<j))){
                    continue;
                }
                for(int k=0; k<statements.size(); k++){
                    if((i&(1<<k)) && statements[j][k]==0){
                        chk=-1; break;
                    }
                    else if(!(i&(1<<k)) && statements[j][k]==1){
                        chk=-1; break;
                    }
                }
                if(chk==-1){break;}
            }
            if(chk==1){
                int cnt=0;
                int n1=i;
                while(n1>0){
                    if(1&n1){cnt++;}
                    n1=n1>>1;
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};

19) Find all possible paths from top to bottom
EasyAccuracy: 78.77%Submissions: 9K+Points: 2
Matrix Partners India: Exclusive Job-A-Thon | Apply to 15+ Companies via 1 Hiring Challenge | Starting from 29th April onwards

banner
Given a N x M grid. Find All possible paths from top left to bottom right.From each cell you can either move only to right or down.

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution
{
public:
    // a function which check whether our step is safe or not
    bool isSafe(int r, int c, vector<vector<int>> &grid, int n, int m)
    {
        return (r < n and c < m and grid[r][c] != -1); // return true if all values satisfied else false
    }

    void findAllPossiblePaths(vector<vector<int>> &grid, int r, int c, int n, int m, vector<int> &ans, vector<vector<int>> &paths)
    {
        // when we hit the last cell we reach to destination then directly push the path
        if (r == n - 1 and c == m - 1)
        {
            ans.push_back(grid[r][c]);
            paths.push_back(ans); // function to display the path stored in ans vector
            ans.pop_back();       // pop back because we need to backtrack to explore more path
            return;
        }

        // we will store the current value in ch and mark the visited place as -1
        int ch = grid[r][c];

        ans.push_back(ch); // push the path in ans array
        grid[r][c] = -1;   // mark the visited place with -1

        // if is it safe to take next downward step then take it
        if (isSafe(r + 1, c, grid, n, m))
        {
            findAllPossiblePaths(grid, r + 1, c, n, m, ans, paths);
        }

        // if is it safe to take next rightward step then take it
        if (isSafe(r, c + 1, grid, n, m))
        {
            findAllPossiblePaths(grid, r, c + 1, n, m, ans, paths);
        }

        // backtracking step we need to make values original so to we can visit it by some another path
        grid[r][c] = ch;

        // remove the current path element we explore
        ans.pop_back();
        return;
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> paths;
        vector<int> ans;
        findAllPossiblePaths(grid, 0, 0, n, m, ans, paths);
        return paths;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends

20) Combinations 
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

class Solution {
public:
    vector<vector<int>> result;

    void solve(int start, int k, int n, vector<int>& temp) {
        if (k == 0) {
            result.push_back(temp);
            return;
        }
        
        for (int i=start; i<=n; i++) {
            temp.push_back(i);
            solve(i+1, k-1, n, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, k, n, temp);
        return result;
    }
};

21) Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<string>& ans, string temp) {
        temp += to_string(root->val);
        if (root->left == NULL && root->right == NULL) ans.push_back(temp);
        else {
            temp += "->";
            if (root->left) dfs(root->left, ans, temp);
            if (root->right) dfs(root->right, ans, temp);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) return ans;
        
        string temp = "";
        dfs(root, ans, temp);
        return ans;
    }
};

22) An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

class Solution {
public:
    void helper(int n, vector<int>& res){
        if(n==1){
            res.push_back(0);
            res.push_back(1);
            return ;
        
        }
        helper(n-1,res);
        int i= res.size()-1;
        while(i>=0){
            int val= res[i] | 1<<(n-1);
            res.push_back(val);
            i--;
        }
    }
    vector<int> grayCode(int n) {
        vector<int> res;
        helper(n,res);
        return res;

    }
};

23) Letter combinations of phone number
class Solution {
public:
    vector<string> result;

    void solve(int idx, string& digits, string& temp, unordered_map<char, string>& mp) {
        if (idx >= digits.length()) {
            result.push_back(temp);
            return;
        }

        string str = mp[digits[idx]];

        for (int i=0; i<str.size(); i++) {
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
        } 
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";
        solve(0, digits, temp, mp);

        return result;
    }
};

24) Generate Parantehsis - Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
class Solution {
public:
    vector<string> result;

    void solve(string curr, int n, int open, int close) {
        if (curr.length() == 2*n) {
            result.push_back(curr);
            return;
        }

        if (open < n) {
            solve(curr+'(', n, open+1, close);
        }
        

        if (close < open) {
            solve(curr+')', n, open, close+1);
            }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        int open = 0, close = 0;
        solve(curr, n, open, close);
        return result;
    }
};
25) Given a string s, you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings.

Example 1:

Input:
s = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".

//Back-end complete function template in C++

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    void permute(string S, int start, int end, string current, vector<string>& result) {
        // base case: when we have reached the end of the string,
        // add the current permutation to the result.
        if (start > end) {
            result.push_back(current);
            return;
        }

        // include the current character in the permutation and
        // recurse for the next character.
        current.push_back(S[start]);
        permute(S, start + 1, end, current, result);

        // insert a space character after the current character,
        // creating a new permutation, and recurse for the next character.
        current.insert(current.length() - 1, 1, ' ');
        permute(S, start + 1, end, current, result);
    }

    // Function to generate all permutations of the given string.
    vector<string> permutation(string S) {
        vector<string> result;
        string current;

        // start with the first character of the string as the current character.
        current.push_back(S[0]);

        // call the permutation function to generate all permutations.
        permute(S, 1, S.length() - 1, current, result);

        // sort the permutations in lexicographical order.
        sort(result.begin(), result.end());

        // return the list of permutations.
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}

// } Driver Code Ends

26) Permuattions 2 (with reptetions)
class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(int idx, vector<int>& nums) {
        if (idx >= n) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> st;
        for (int i=idx; i<n; i++) {
            if (st.count(nums[i])) continue;
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);
            solve(idx+1, nums);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        solve(0, nums);
        return result;
    }
};

27) The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1;
        string ans="";
        while(true){
            ans=ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};

28) You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

class Solution {
public:
    bool hasDuplicate(string& s1, string& s2) {
        int arr[26] = {0};

        for (char& ch: s1) {
            if (arr[ch-'a'] > 0) return true;
            arr[ch-'a']++;
        }

        for (char &ch: s2) {
            if (arr[ch-'a'] > 0) return true;
            arr[ch-'a']++;
        }

        return false;
    }

    int solve(int i, vector<string>& arr, string temp, int n) {
        if (i >= n) return temp.length();

        int include = 0;
        int exclude = 0;

        if (hasDuplicate(arr[i], temp)) {
            exclude = solve(i+1, arr, temp, n);
        } else {
            exclude = solve(i+1, arr, temp, n);
            include = solve(i+1, arr, temp+arr[i], n);
        }

        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int i = 0;
        string temp = "";
        return solve(i, arr, temp, n);
    }
};

29) Palindrmoe partioning - Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

class Solution {
public:
    int n;
    vector<vector<string>> result;

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int idx, string& s, vector<string>& temp) {
        if (idx >= n) {
            result.push_back(temp);
            return;
        }

        for (int i=idx; i<n; i++) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> temp;
        solve(0, s, temp);
        return result;
    }
};

30) Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool isSafe(int v, bool graph[101][101], int color[101], int c, int V) {
        // checking if the connected nodes to v have same colour as c.
        for (int i = 0; i < V; i++)
            if (graph[v][i] && c == color[i]) return false;
    
        // returning true if no connected node has same colour.
        return true;
    }
    
    bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v,
                           int V) {
        // if all vertices have been assigned colour then we return true.
        if (v == V) return true;
    
        for (int c = 1; c <= m; c++) {
            // checking if this colour can be given to a particular node.
            if (isSafe(v, graph, color, c, V)) {
                // assigning colour to the node.
                color[v] = c;
    
                // calling function recursively and checking if other nodes
                // can be assigned other colours.
                if (graphColoringUtil(graph, m, color, v + 1, V) == true)
                    // returning true if the current allocation was successful.
                    return true;
    
                // if not true, we backtrack and remove the colour for that node.
                color[v] = 0;
            }
        }
        // if no colour can be assigned, we return false.
        return false;
    }
    
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int *color = new int[n];
        for (int i = 0; i < n; i++) color[i] = 0;
    
        // checking if colours can be assigned.
        if (graphColoringUtil(graph, m, color, 0, n) == false) {
            return false;
        }
    
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

31) Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order. 

class Solution
{
    public:
        vector<string>find_permutation(string S)
        {
            vector<string>res;

            // sort the string in lexicographically order
            sort(S.begin(), S.end());

            do
            {
                // keep adding while there is next permutation
                res.push_back(S);
            }while(next_permutation(S.begin(), S.end()));

            return res;
        }
};
32) Combination sum - Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

class Solution {
public:
    void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            combination(candidates, target-candidates[i], curr, result, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        
        combination(candidates, target, curr, result, 0);
        return result;
    }
};

34) Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

class Solution {
public:
    void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1])
                continue; //ignore duplicate elements
            curr.push_back(candidates[i]);
            combination(candidates, target-candidates[i], curr, result, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); //because we will ignore duplicate elements
        combination(candidates, target, curr, result, 0);
        return result;
    }
};

35) Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

class Solution {
public:
    vector<vector<int>> result;

    void generate(int num, vector<int>& temp, int k, int target) {
        if(target == 0 && temp.size() == k) {
            result.push_back(temp);
            return;
        }

        if(num >= 10 || target < 0) {
            return;
        }

        for(int i = num; i<10; i++) {
            temp.push_back(i);
            generate(i+1, temp, k, target-i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int num = 1;
        vector<int> temp;

        generate(num, temp, k, n);

        return result;
    }
};

36) Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

class Solution {
public:
    //The main crux here is that you will have to start again from index 0 to consider all possible combinations
    //For example : in [1,2,3], target = 4
    //We can also have [1, 2, 1] -> I added 1 and then 2 and then again added 1 (This is possible only when we
    //restart from 0 also)
    int solve_1(vector<int>& nums, int target, int pos, vector<int>& cache) {
        if (pos == nums.size() || target <= 0) {
            return (target == 0) ? 1 : 0;
        }
        
        if (cache[target] != -1) {
            return cache[target];
        }
        
        int take = solve_1(nums, target - nums[pos], 0, cache); //restart from 0 also (This will take care of taking an element unlimited times)
        int skip = solve_1(nums, target, pos + 1, cache);
        
        return cache[target] = take + skip;
    }
    
    int solve_2(vector<int>& nums, int target, vector<int>& t) {
        if(nums.size() == 0)
            return 0;
        
        if(target == 0)
            return t[target] = 1;
        if(t[target] != -1)
            return t[target];
        
        int result = 0;
        //This for loop technique is nothin but just a top-down approach
        /*
            i.e. we have 4, it can be broken by 1, 2, or 3
            (broken by 1) -> we are now left with (4-1) = 3, now further this 3 can be broken by 1, 2, or 3 and so on.
            
            Similaryly,
            (broken by 2) -> we are now left with (4-2) = 2, now further this 2 can be broken by 1, 2, or 3 and so on.
            Similaryly,
            (broken by 3) -> we are now left with (4-3) = 1, now further this 1 can be broken by 1, 2, or 3 and so on.
            
            Until we reach to leaves of the DFS tree
        */
        for(int i = 0; i<nums.size(); i++) {
            if(target >= nums[i]) //just an optimization
                result += solve_2(nums, target-nums[i], t);
        }
        
        return t[target] = result;
        
    }
    
    int solve_3(vector<int>& nums, int target) {
        vector<unsigned long long> t(target+1, 0);
        t[0] = 1;
        
        for(unsigned long long i = 1; i<=target; i++) {
            for(unsigned long long j = 0; j<nums.size(); j++) {
                
                if(i >= nums[j])
                    t[i] = t[i] + t[i-nums[j]];
            }
        }
        
        return t[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> t(target+1, -1);
        
        //return solve_1(nums, target, 0, t);
        
        //return solve_2(nums, target, t);
        
        return solve_3(nums, target);
        
        
    }
};

37) Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

class Solution{
public:
    vector<string> result;

    bool isSafe(int i, int j, int n) {
        return i >= 0 && i < n && j >=0 && j < n;
    }

    void solve(int i, int j, int n, vector<vector<int>>& maze, string& path) {
        if (!isSafe(i, j, n)) return;
        if (maze[i][j] == 0) return;
        if (i == n-1 && j == n-1) {
            result.push_back(path);
            return;
        }
        
        maze[i][j] = 0;
        path.push_back('D'); solve(i+1, j, n, maze, path); path.pop_back();
        path.push_back('U'); solve(i-1, j, n, maze, path); path.pop_back();
        path.push_back('R'); solve(i, j+1, n, maze, path); path.pop_back();
        path.push_back('L'); solve(i, j-1, n, maze, path); path.pop_back();
        maze[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &maze, int n) {
        string path = "";
        solve(0, 0, n, maze, path);
        return result;
    }
};

38) A Maze is given as n*n matrix of blocks where source block is the upper left most block i.e., matrix[0][0] and destination block is lower rightmost block i.e., matrix[n-1][n-1]. A rat starts from source and has to reach the destination. The rat can move in only two directions: first forward if possible or down. If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward. In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j]. In this variation, Rat is allowed to jump multiple steps at a time instead of 1. Find a matrix which describes the position the rat to reach at the destination.
 

Example:

Input: {{2,1,0,0},{3,0,0,1},{0,1,0,1},
{0,0,0,1}}
Output: {{1,0,0,0},{1,0,0,1},{0,0,0,1},
{0,0,0,1}}
Explanation: Rat started with matrix[0][0] and 
can jump up to 2 steps right/down. First check 
matrix[0][1] as it is 1, next check 
matrix[0][2] ,this won't lead to the solution. 
Then check matrix[1][0], as this is 3(non-zero)
,so we can make 3 jumps to reach matrix[1][3]. 
From matrix[1][3] we can move downwards taking 
1 jump each time to reach destination at 
matrix[3][3].'

//Back-end complete function template in C++

class Solution {
public:
	//Function to check if the current position is safe to move or not.
	bool isSafe(int x, int y, vector<vector<int>>&matrix){
		int n = matrix.size();
		//Checking if the position is within the matrix boundaries and not a wall (0).
		return (x >= 0 and x < n and y >=0 and y < n and matrix[x][y] != 0);
	}
	
	//Helper function to find the shortest distance.
	bool helper(int x, int y, vector<vector<int>>&matrix, vector<vector<int>>&sol){
		int n = matrix.size();
		//If reached to the destination, mark it as 1 in the solution matrix and return true.
		if(x == n-1 and y == n-1){
			sol[x][y] = 1;
			return true;
		}
		//If the current position is safe to move.
		if(isSafe(x, y, matrix)){
			//Mark the current position as 1 in the solution matrix.
			sol[x][y] = 1;
			//Try moving right or down for each step within the range of value in the current position.
			for(int step = 1; step <= matrix[x][y] and step < n; step++){
				//Try moving right.
				if(helper(x, y+step, matrix, sol))
					return true;
				//Try moving down.
				if(helper(x+step, y, matrix, sol))
					return true;
			}
			//If no path found, mark the current position as 0 in the solution matrix and return false.
			sol[x][y] = 0;
			return false;
		}
		//If the current position is not safe, return false.
		return false;
	}
	
	//Function to find the shortest distance in the matrix.
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
		int  n = matrix.size();
		//Create a solution matrix of size n*n and fill it with 0s.
		vector<vector<int>>sol(n, vector<int>(n, 0));
		//Call the helper function to find the shortest distance. If no path is found, return {-1}.
		helper(0, 0, matrix, sol);
		vector<vector<int>>ans;
		ans.push_back({-1});
		return sol[n-1][n-1] == 0 ? ans : sol;
	}

};


39) There are N coins and K people. Each of them can propose a method of distribution of the coins amongst themselves when their chance comes and a vote will occur in favour or against his distribution method between all those members. The person proposing that method of distribution wins the vote if he gets equal or more votes in favour than in against his proposal else he loses. Loosing he would be eliminated and then the next member will now propose his method of distribution amongst the remaining members.

Each person while proposing his method of distribution wants to get the maximum number of coins as well as win the vote.

Each person is smart and knows all the possibilities that may occur from their vote and will cast their vote accordingly.

The first proposal will always be given by 1 if he loses will be followed by 2 and so on (till the Kth person).

In the distribution of the 1st person print the amount of coins each of K people is proposed to get so that he wins the vote.

Example 1:

Input:
N = 100 and K = 2
Output: 100 0
Explanation:
To get the maximum coins the 1st person will propose the 
distribution 100,0 when the vote occurs he will obviously
vote for himself and the second person against him. 
The result of the vote will be 1-1 which means he will 
survive (tie here means victory) the vote.

vector<int> coinsGame(int N, int K){
    vector<int>ans(K,0);
    ans[0] = N;
    for(int i=1;i<K;i++) {
        if(i%2==0) {
            ans[0]--;
            ans[i]++;
        }
    }
    return ans;
}

40) N queens
/*
    Company Tags  : Accolite, Amazon, Visa, MAQ Software, Amdocs, Twitter, Qualcomm, Google 
    Leetcode Link : https://leetcode.com/problems/n-queens/
*/

/*
    Time complexity: O(N!)
    Unlike the brute force approach, we will only place queens on squares that aren't under attack.
    For the first queen, we have N options. For the next queen, we won't attempt to place it in the
    same column as the first queen, and there must be at least one square attacked diagonally by the
    first queen as well. Thus, the maximum number of squares we can consider for the second queen is
    (N−2). For the third queen, we won't attempt to place it in 2 columns already occupied by the first
    2 queens, and there must be at least two squares attacked diagonally from the first 2 queens.
    Thus, the maximum number of squares we can consider for the third queen is (N-4).
    This pattern continues, resulting in an approximate time complexity of O(N!)
*/

//Approach-1 (Simple dfs)
class Solution {
public:
    vector<vector<string>> result;
    bool isValid(vector<string>& board, int row, int col) {
        //look for up
        for(int i = row; i>=0; i--) {
            if(board[i][col] == 'Q')
                return false;
        }
        
        //check left diagonal upwards
        for(int i = row, j = col; i>=0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }
        
        //check right diagonal upwards
        for(int i = row, j = col; i>=0 && j<board.size(); i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }
        
        /*
			Wait a second, Why didn't I check any squares downwards ???
			If you notice, every time I am calling dfs(board, row+1); i.e. after
			placing a Queen at a row, I move down. So, It's guaranteed I will
			not get any Queen downwards.
			Example :

			For n = 4

            _   _    _  Q   (Put int the first row)
            Q  _   _   _    (While putting here, I only need to see above of me because I have not populated any Q in downwards)
            _   _   Q  _    (Same,  While putting here, I only need to see above of me because I have not populated any Q in downwards)

            So, on

		*/
        
        
        return true;
    }
    void dfs(vector<string>& board, int row) {
        if(row == board.size()) {
            result.push_back(board);
            return;
        }
        
        /*
            place one queen at every row and check before placing
            in every directions where there is risk if being attackes
            i.e. up, diagonally because we are placing queens from
            top row to bottom row, so we need to check if we put a queen
            vertically up in some row or diagonally upwards in some row
        */
        for(int i = 0; i<board.size(); i++) {
            if(isValid(board, row, i)) {
                board[row][i] = 'Q';
                
                dfs(board, row+1);
                
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return {};
        vector<string> board(n, string(n, '.')); 
        //For, n = 3, board = {"...", "...", "..."} initially
        
        dfs(board, 0);
        
        return result;
    }
};

//Approach-2 (Leetcode's solution simplified and explained)
class Solution {
public:
    vector<vector<string>> result;
    void dfs(vector<string>& board, int row, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antiDiags) {
        if(row == board.size()) {
            result.push_back(board);
            return;
        }
        
        /*
            For a square (i, j) :
            Diagonally (i-j)      is constant
            Anti diagonally (i+j) is constant
            
            We can use this to find which square(i, j)
            has a risk of being attacked by another queen
            plaed already in 'diagonal', or 'anti-diagonal'
            or 'column'
        */
        
        for(int col = 0; col<board.size(); col++) {
            int diag_id       = row-col;
            int anti_diag_id  = row+col;
            
            /*
                If the col, or diagonal or anti_diaonal
                are used means one of them has a Queen placed
                already which can attack, so look for other column
            */
            if(cols.find(col) != cols.end() ||
              diags.find(diag_id) != diags.end() ||
              antiDiags.find(anti_diag_id) != antiDiags.end())
                continue;
            
            cols.insert(col);
            diags.insert(diag_id);
            antiDiags.insert(anti_diag_id);
            board[row][col] = 'Q';
            
            
            dfs(board, row+1, cols, diags, antiDiags);

            cols.erase(col);
            diags.erase(diag_id);
            antiDiags.erase(anti_diag_id);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return {};
        vector<string> board(n, string(n, '.')); 
        //For, n = 3, board = {"...", "...", "..."} initially
        
        int start_row = 0;
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antiDiags;
        dfs(board, start_row, cols, diags, antiDiags);
        
        return result;
    }
};


41) N queens 2 - The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

/*
    Company Tags  : Accolite, Amazon, Visa, MAQ Software, Amdocs, Twitter, Qualcomm, Google 
    Leetcode Link : https://leetcode.com/problems/n-queens-ii/
*/

/*
    A simple approach will be the same as N Queens problem. Instead of returning all the configurations of board (vector<vector<string>>),
    here we return the count of total configurations. Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/N-Queens.cpp
    
    But, you don't need to form boards and configurations to count the total configurations. See the solution below.
*/
class Solution {
public:
    int count = 0;
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antiDiags;
    void dfs(int row, int n) {
        if(row == n) {
            count++;
            return;
        }
        
        for(int col = 0; col<n; col++) {
            int d  = row-col;
            int ad = row+col;
            
            if(cols.count(col) || diags.count(d) || antiDiags.count(ad))
                continue;
            
            cols.insert(col);
            diags.insert(d);
            antiDiags.insert(ad);
            
            dfs(row+1, n);
            
            cols.erase(col);
            diags.erase(d);
            antiDiags.erase(ad);
            
        }
    }
    vector<vector<string>> result;
    int totalNQueens(int n) {
        count = 0;
        if(n == 1)
            return 1;
        if(n <= 3)
            return count;
        
        dfs(0, n);
        
        return count;
        
    }
};

42) Given a string S that contains only digits (0-9) and an integer target, return all possible strings to insert the binary operator ' + ', ' - ', or ' * ' between the digits of S so that the resultant expression evaluates to the target value.

Note:

Operands in the returned expressions should not contain leading zeros. For example, 2 + 03 is not allowed whereas 20 + 3 is fine. It is allowed to not insert any of the operators.

If no solution is found, return an empty string array.
Example 1:

Input:
S = "123"
target = 6
Output: { "1*2*3", "1+2+3"}
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

//Back-end complete function template in C++

class Solution {
  public:
    // vector to store the answer
    vector<string> ans;
    
    // Recursive function to generate all possible expressions
    void f(int i, string s, long sum, long prev, string &num, int target) {
        // Base case
        if (i == num.size()) {
            // If the current sum equals target, add expression to the answer vector
            if (sum == target) {
                ans.push_back(s);
                return;
            }
        }
        
        // Recursively generate expressions by considering different operations
        for (int j = i; j < num.size(); ++j) {
            // Ignore leading zeros in multi-digit numbers
            if (j > i && num[i] == '0') break;
            
            // Convert the substring to a number
            long number = stol(num.substr(i, j - i + 1));
            
            // Handle different cases based on whether it is the first number or not
            if (i == 0)
                f(j + 1, s + num.substr(i, j - i + 1), number, number, num, target);
            else {
                f(j + 1, s + "+" + num.substr(i, j - i + 1), sum + number, number, num, target);
                f(j + 1, s + "-" + num.substr(i, j - i + 1), sum - number, -number, num, target);
                f(j + 1, s + "*" + num.substr(i, j - i + 1), sum - prev + prev * number, prev * number, num, target);
            }
        }
    }

    // Function to generate all possible expressions that evaluate to the target
    vector<string> addOperators(string S, int target) {
        f(0, "", 0, 0, S, target); // Start the recursive function
        return ans; // Return the answer vector
    }
};

43) You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

The division operator '/' represents real division, not integer division.
For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
You cannot concatenate numbers together
For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
Return true if you can get such expression that evaluates to 24, and false otherwise.

 

Example 1:

Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24
Example 2:

Input: cards = [1,2,1,2]
Output: false

class Solution {
public:
    bool valid(double a, double b) {
        return fabs(a + b - 24.0) < 0.0001 or fabs(a - b - 24.0) < 0.0001 or
               fabs(a * b - 24.0) < 0.0001 or (b != 0 and fabs(a / b - 24.0) < 0.0001);
    }
    
    bool valid(double a, double b, double c) {
        return valid(a + b, c) or valid(a, b + c) or valid(a - b, c) or
               valid(a, b - c) or valid(a * b, c) or valid(a, b * c) or
               valid(a / b, c) or valid(a, b / c);
    }
    
    bool get_perm(int idx, vector<double>& cards) {
        if (idx == 4) {
            return valid(cards[0] + cards[1], cards[2], cards[3]) or
                   valid(cards[0], cards[1] + cards[2], cards[3]) or
                   valid(cards[0], cards[1], cards[2] + cards[3]) or
                   valid(cards[0] - cards[1], cards[2], cards[3]) or
                   valid(cards[0], cards[1] - cards[2], cards[3]) or
                   valid(cards[0], cards[1], cards[2] - cards[3]) or
                   valid(cards[0] * cards[1], cards[2], cards[3]) or
                   valid(cards[0], cards[1] * cards[2], cards[3]) or
                   valid(cards[0], cards[1], cards[2] * cards[3]) or
                   valid(cards[0] / cards[1], cards[2], cards[3]) or
                   valid(cards[0], cards[1] / cards[2], cards[3]) or
                   valid(cards[0], cards[1], cards[2] / cards[3]);
        }
        
        bool res = false;
        unordered_set<int> s;
        for (int i = idx; i < 4 and !res; i++) {
            if (s.count(cards[i]))
                continue;
            s.insert(cards[i]);
            swap(cards[idx], cards[i]);
            res |= get_perm(idx + 1, cards);
            swap(cards[idx], cards[i]);
        }
        return res;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> cards;
        for (auto& x : nums)
            cards.push_back((double)x);
        return get_perm(0, cards);
    }
};

44) There are two types of persons:

The good person: The person who always tells the truth.
The bad person: The person who might tell the truth and might lie.
You are given a 0-indexed 2D integer array statements of size n x n that represents the statements made by n people about each other. More specifically, statements[i][j] could be one of the following:

0 which represents a statement made by person i that person j is a bad person.
1 which represents a statement made by person i that person j is a good person.
2 represents that no statement is made by person i about person j.
Additionally, no person ever makes a statement about themselves. Formally, we have that statements[i][i] = 2 for all 0 <= i < n.

Return the maximum number of people who can be good based on the statements made by the n people.

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans=0;
        for(int i=1; i<(1<<statements.size()); i++){
            int chk=1;
            for(int j=0; j<statements.size(); j++){
                if(!(i&(1<<j))){
                    continue;
                }
                for(int k=0; k<statements.size(); k++){
                    if((i&(1<<k)) && statements[j][k]==0){
                        chk=-1; break;
                    }
                    else if(!(i&(1<<k)) && statements[j][k]==1){
                        chk=-1; break;
                    }
                }
                if(chk==-1){break;}
            }
            if(chk==1){
                int cnt=0;
                int n1=i;
                while(n1>0){
                    if(1&n1){cnt++;}
                    n1=n1>>1;
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};

45) Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.

Note: Each subset should be sorted.

Example 1:

Input: N = 3, arr[] = {2,1,2}
Output:(),(1),(1 2),(1 2 2),(2),(2 2)
Explanation: 
All possible subsets = (),(2),(1),(1,2),(2),(2,2),(2,1),(2,1,2)
After Sorting each subset = (),(2),(1),(1,2),(2),(2,2),(1,2),(1,2,2) 
Unique Susbsets in Lexicographical order = (),(1),(1,2),(1,2,2),(2),(2,2)

class Solution
{
    public:
    void AllSubsetsHelper(vector<int> A, int index, int n, vector<int> current,
    vector<vector<int> > &result)
    {
        //if all elements are iterated then we store current vector in result.
        if(index >= n){
            result.push_back(current);
            return;
        }
        
        int curIndex=index+1;
        //checking for duplicate elements.
        while(curIndex < n && A[curIndex] == A[index]){
            curIndex++;
        }
        
        int count = curIndex - index;
        
        //inserting all the subsets in current.
        for(int i=0;i<=count;i++)
        {
            for(int j=0;j<i;j++){
                current.push_back(A[index]);
            }
            //calling function recursively for adding further subsets.
            AllSubsetsHelper(A, curIndex, n, current, result);
            
            for(int j=0;j<i;j++)
            {
                //backtracking to exclude current combinations and 
                //include further combinations.
                current.pop_back();
            }
        }
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> A, int n)
    {
        vector<vector<int> > result;
        vector<int> current;
        sort(A.begin(),A.end());
        AllSubsetsHelper(A, 0, n, current, result);    
        
        //sorting for ascending output.
        sort(result.begin(),result.end());
        
        //returning the result.
        return result;
    }
};


46) Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5

// function to find maximum integer possible by

class Solution
{
    public:
    //Function to compare two strings and updating res
    //which stores the string with larger number.
    void match(string& str, string& res)
    {
        for(int i=0; i<str.size(); i++)
        {
            if( res[i] > str[i] )
                return;
            //if str[i] is greater, we update res as str or store
            //the larger value in res.
            if( res[i] < str[i] )
            {
                res = str;
                return;
            }
        }
    }

    public:
    //Function to set highest possible digits at given index.
    void setDigit(string& str, int index, string& res, int k)
    {
        // base case
        if(k==0 || index==str.size()-1)
        {
            match(str,res);
            return;
        }
        
        int maxDigit = 0;
        
        //finding maximum digit for placing at given index.
        for(int i=index; i<str.size(); i++)
            maxDigit = max( maxDigit, str[i]-'0' );
        
        
        // swapping isn't needed in this case.
        if( str[index]-'0' == maxDigit )
        {
            setDigit(str, index+1, res, k);
            return;
        }
        
        for(int i=index+1; i<str.size(); i++)
        {
            // if max digit is found at current index.
            if( str[i]-'0' == maxDigit )
            {
                //swapping to get the maximum digit at required index.
                swap( str[index] , str[i] );
                
                //calling recursive function to set the next digit.
                setDigit(str, index+1, res, k-1);
                
                // backtracking
                swap( str[index] , str[i] );
            }
        }
    }

    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        string res = str;
        setDigit(str, 0, res, k);
        
        //returning the result.
        return res;
    }

};



47)
2305. Fair Distribution of Cookies
Solved
Medium
Topics
Companies
Hint
You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.

 

Example 1:

Input: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=vcaAC2fqFpk
    Company Tags                : <soon, I will update>
    Leetcode Link               : https://leetcode.com/problems/fair-distribution-of-cookies/
*/


//TC : O(K^n)
class Solution {
public:
    
    int result = INT_MAX;
    int n;
    
    void solve(int idx, vector<int>& cookies, vector<int>& children, int k) {
        if(idx == cookies.size()) {
            
            int ans = *max_element(begin(children), end(children));
            result = min(result, ans);
            return;
        }
        
        int candy = cookies[idx];
        for(int i = 0; i<k; i++) {
            children[i] += candy;
            
            solve(idx+1, cookies, children, k);
            
            children[i] -= candy;
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(k);
        solve(0, cookies, children, k);
        
        return result;
    }
};

48) max number of achievable transfers
class Solution {
public:
    int result = INT_MIN;
    int m;

    void solve(int idx, int count, int n, vector<int>& resultant, vector<vector<int>>& requests) {
        if (idx >= m) {
            bool allZero = true;

            for (int &x: resultant) {
                if (x != 0) {
                    allZero = false;
                    break;
                }
            }

            if (allZero == true) result = max(result, count);
            return;
        }

        int from = requests[idx][0];
        int to = requests[idx][1];

        resultant[from]--;
        resultant[to]++;
        solve(idx+1, count+1, n, resultant, requests);
        resultant[from]++;
        resultant[to]--;
        solve(idx+1, count, n, resultant, requests);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();
        vector<int> resultant(n, 0);
        solve(0, 0, n, resultant, requests);
        return result;
    }
};

48) non decreasing subsequence
class Solution {
public:
    int n;
   
    void backtrack(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& result) {
        if(curr.size() > 1)
            result.push_back(curr);
        
        unordered_set<int> st;
        for(int i = idx; i<n; i++) {
            if((curr.empty() || nums[i]  >= curr.back()) && st.find(nums[i]) == st.end()) {
                
                curr.push_back(nums[i]);
                backtrack(nums, i+1, curr, result);
                curr.pop_back();
                
                st.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        n = nums.size();
        vector<vector<int>> result;
    
        
        vector<int> curr;
        
        backtrack(nums, 0, curr, result);
        
        return result;
    }
};


49) word search problem 
class Solution {
public:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n;

    bool find(int i, int j, int idx, vector<vector<char>>& board, string word) {
        if (idx >= word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx] || board[i][j] == '$') return false;

        char temp = board[i][j];
        board[i][j] = '$';
        for (auto &dir: directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (find(ni, nj, idx+1, board, word)) return true;
        }
        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == word[0] && find(i, j, 0, board, word)) return true;
            }
        }

        return false;
    }
};

50) permutation with case change:
#include <bits/stdc++.h>
using namespace std;

void generateP_1(string output, string input) {
    if(input.length() == 0) {
        cout << output << endl;
        return;
    }

    string op1 = output+ input[0];
    string op2 = output + string(1, (islower(input[0])?(char)toupper(input[0]):(char)tolower(input[0])));
    generateP_1(op1, input.substr(1));
    generateP_1(op2, input.substr(1));
}


void generateP_2(int start, string s) {
    cout << s << endl;
    if(start == s.length()) {
        return;
    }

    for(int i = start; i<s.length(); i++) {
        s[i] = islower(s[i])?(char)toupper(s[i]):(char)tolower(s[i]);
        generateP_2(i+1, s);
        s[i] = islower(s[i])?(char)toupper(s[i]):(char)tolower(s[i]);
    }
}

int main() {
    string s = "ab";

    generateP_1("", s);
    cout << "\n------------------\n";
    generateP_2(0, s);
}




 