//Subset Sum Problem
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// dp[N][sum]
int dp[1001][1001];

//int KS(int wt[], int val[], int w, int n) {
int SS(int ar[], int sum, int n) {
    //base condition
    if(n<=0 ) {
        return 0;
    }
    if(sum==0)
        return 1;
    
    if(dp[n][sum] != -1) {
        return dp[n][sum];
    }
    
    if(ar[n-1] <= sum) {
        return dp[n][sum] = ( SS(ar, sum-ar[n-1], n-1) || SS(ar, sum, n-1) ); 
    }
    else if (ar[n-1] > sum) {
        return dp[n][sum] = SS(ar, sum, n-1);
    }
}

int main() {
	// your code goes here
    memset(dp, -1, sizeof(dp));
    int n, sum, ar[1001];
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>ar[i];
    }
  
    cin>>sum;
    
    cout<<SS(ar, sum, n);
    
    return 0;
}
