//unbounded Knapsack
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int KS(int wt[], int val[], int w, int n) {
    //base condition
    if(n==0 || w==0) {
        return 0;
    }
    
    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    
    if(wt[n-1] <= w) {
        return dp[n][w] = std::max( val[n-1] + KS(wt, val, w-wt[n-1], n) , KS(wt, val, w, n-1) ); 
    }
    else if (wt[n-1] > w) {
        return dp[n][w] = KS(wt, val, w, n-1);
    }
}

int main() {
	// your code goes here
    memset(dp, -1, sizeof(dp));
    int n, w, wt[1001], val[1001];
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>wt[i];
    }
    for(int i=0; i<n; i++) {
        cin>>val[i];
    }
    cin>>w;
    
    cout<<KS(wt, val, w, n);
    
    return 0;
}
