#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

bool isPalindrome(string s, int i, int j) {
    if(i>=j)
        return true;
    while(i<j) {
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int Solve(string s, int i, int j) {
    if(i>=j)
        return 0;
    //check if string is palindrome 
    if(isPalindrome(s, i, j) == true)
        return 0;
    
    int left, right, temp, mn = INT_MAX;
    
    if(t[i][j] != -1)
        return t[i][j];
        
    for(int k=i; k<j; k++) {
        if(t[i][k] != -1)
            left = t[i][k];
        else
            left = Solve(s, i, k);
            
        if(t[k+1][j] != -1)
            right = t[k+1][j];
        else
            right = Solve(s, k+1, j);
        
        temp = left + right + 1; //arr[i-1]*arr[k]*arr[j];
        
        if(temp < mn)
            mn = temp;
    }
    return t[i][j] = mn; 
}

int main() {
	// your code goes here
	memset(t, -1, sizeof(t));
	int size;
	string s;
	cin>>s;
	size = s.length();
	cout<<Solve(s, 0, size)<<endl;
	return 0;
}
