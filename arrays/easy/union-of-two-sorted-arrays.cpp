#include <bits/stdc++.h>
using namespace std;

vector < int > sortedArray(vector < int > arr1, vector < int > arr2) {
    int i = 0, j = 0;
    int n = arr1.size(), m = arr2.size();
    vector<int> ans;

    while (i<n && j<m) {
        if (arr1[i] <= arr2[j]) {
            if (ans.size() == 0 || ans.back() != arr1[i]) ans.push_back(arr1[i]);
            i++;
        } 
        else {
            if (ans.size() == 0 || ans.back() != arr2[j]) ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i<n) {
        if (ans.size() == 0 || ans.back() != arr1[i]) ans.push_back(arr1[i]);
        i++;
    }

    while (j<m) {
        if (ans.size() == 0 || ans.back() != arr2[j]) ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}
