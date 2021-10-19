#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[10001][10001];

int LCS(string x, string y, int n, int m) {
    if(n==0 || m==0) {
        return 0;
    }
    
    if(dp[n][m] != -1)
        return dp[n][m];
        
    else if(x[n-1] == y[m-1]) {
        //cout<<x[m-1];
        return dp[n][m] = 1 + LCS(x, y, n-1, m-1);
    }
    else
        return dp[n][m] = std::max(LCS(x, y, n-1, m), LCS(x, y, n, m-1));
}

int main() {
	// your code goes here
	
	int t, m, n, length;
	string X, Y;
	cin>>t;
	while(t--) {
	    memset(dp, -1, sizeof(dp));
	    cin>>X;
	    cin>>Y;
	    
	    m = X.length();
	    n = Y.length();
	    cout<<X<<"--"<<m<<"   "<<Y<<"--"<<n<<endl;
	    length = LCS(X, Y, m, n);
	    //min no of deletions
	    cout<<m-length<<endl;
	    //min no of insertions
	    cout<<n-length<<endl;
	}
	return 0;
}
