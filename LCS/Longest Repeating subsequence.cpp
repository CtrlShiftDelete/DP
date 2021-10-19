#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[10001][10001];

int LCS(string x, int n, int m) {
    if(n==0 || m==0) {
        return 0;
    }
    
    if(dp[n][m] != -1)
        return dp[n][m];
        
    else if(x[n-1] == x[m-1] && n!=m) {
        //cout<<x[m-1];
        return dp[n][m] = 1 + LCS(x, n-1, m-1);
    }
    else
        return dp[n][m] = std::max(LCS(x, n-1, m), LCS(x, n, m-1));
}

int main() {
	// your code goes here
	
	int t, m, n, length;
	string X, Y;
	cin>>t;
	while(t--) {
	    memset(dp, -1, sizeof(dp));
	    cin>>X;
	    //cin>>Y;
	    
	    m = X.length();
	    //n = Y.length();
	    cout<<X<<"--"<<m<<"   "<<Y<<"--"<<n<<endl;
	    cout<< LCS(X, m, m)<<endl;
	   
	}
	return 0;
}
