#include <bits/stdc++.h> 
using namespace std;

//method - 1

vector<int> rotateArray(vector<int>arr, int d) {
    int n = arr.size();
    d = d % n;
    
    int temp[d];
    for (int i=0; i<d; i++) temp[i] = arr[i];
    for (int i=d; i<n; i++) arr[i-d] = arr[i];
    for (int i=n-d; i<n; i++) arr[i] = temp[i-(n-d)];

    return arr;
}

//method - 2 (optimal)

vector<int> rotateArray(vector<int>a, int d) {
    int n = a.size();
    
    reverse(a.begin(), a.begin()+d);
    reverse(a.begin()+d, a.end());
    reverse(a.begin(), a.end());

    return a;
}

