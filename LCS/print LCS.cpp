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
	
	int t, m, n;
	string X, Y, result="";
	cin>>t;
	while(t--) {
	    memset(dp, -1, sizeof(dp));
	    cin>>X;
	    cin>>Y;
	    
	    m = X.length();
	    n = Y.length();
	    cout<<X<<"--"<<m<<"   "<<Y<<"--"<<n<<endl;
	    cout<<LCS(X, Y, m, n)<<endl;
	    	// print LCS
	    int i = m, j = n;
    	while(i>0 && j>0) {
	    if(X[i-1] == Y[j-1]) {
	        result.push_back(X[i-1]);
	        i--;
	        j--;
	    }
	    else {
	        if(dp[i][j-1] > dp[i-1][j]) {
	            j--;
	        }
	        else {
	            i--;
	        }
	    }
	        
	}
	
	reverse(result.begin(), result.end());
	for(int i=0; i<result.size(); i++)
	    cout<<result[i];
	   
	}


	return 0;
}
