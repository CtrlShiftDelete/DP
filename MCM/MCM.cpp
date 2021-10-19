#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int Solve(int arr[], int i, int j) {
    if(i>=j)
        return 0;
    
    int left, right, temp, mn = INT_MAX;
    
    if(t[i][j] != -1)
        return t[i][j];
    
    for(int k=i; k<j; k++) {
        //temp = Solve(arr, i, k) + Solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        //more optimized code
        if(t[i][k] != -1)
            left = t[i][k];
        else
            left = Solve(arr, i, k);
        
        if(t[k+1][j] != -1)
            right = t[k+1][j];
        else
            right = Solve(arr, k+1, j);
            
        temp = left + right + arr[i-1]*arr[k]*arr[j];
        
    if(temp < mn)
        mn = temp;
    }
    return t[i][j] = mn;
}

int main() {
	// your code goes here
	memset(t, -1, sizeof(t));
	int n, arr[1001];
	cin>>n;
	for(int i=0; i<n; i++)
	    cin>>arr[i];
	cout<<Solve(arr, 1, n-1)<<endl;
	return 0;
}
