//Rod Cutting Problem
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int KS(int length[], int price[], int w, int n) {
    //base condition
    if(n==0 || w==0) {
        return 0;
    }
    
    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    
    if(wt[n-1] <= w) {
        return dp[n][w] = std::max( price[n-1] + KS(length, price, w-length[n-1], n) , KS(length, price, w, n-1) ); 
    }
    else if (wt[n-1] > w) {
        return dp[n][w] = KS(length, price, w, n-1);
    }
}

int main() {
	// your code goes here
    memset(dp, -1, sizeof(dp));
    int n, w, length[1001], price[1001];
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>length[i];
    }
    for(int i=0; i<n; i++) {
        cin>>price[i];
    }
// PRofit = w;
    cin>>w;
    
    cout<<KS(length, price, w, n);
    
    return 0;
}
