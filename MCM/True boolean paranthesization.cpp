#include <iostream>
#include <bits/stdc++.h>
//#include <string>
using namespace std;

unordered_map<string, int> mp;

int Solve(string s, int i, int j, bool isTrue) {
    if(i>j)
        return true;
    if(i==j) {
        if(isTrue == true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    
    if(mp.find(temp) != mp.end())
        return mp[temp];
    
    int ans = 0;
    
    for(int k=i+1; k<=j-1; k+=2) {
        int lt = Solve(s, i, k-1, true);
        int lf = Solve(s, i, k-1, false);
        int rt = Solve(s, k+1, j, true);
        int rf = Solve(s, k+1, j, false);
        
        if(s[k] == '&') {
            if(isTrue == true) {
                ans += lt*rt;
            }
            else
                ans += lt*rf + lf*rt + lf*rf;
        }
        
        else if(s[k] == '|') {
            if(isTrue == true)
                ans += lt*rt + lt*rf + lf*rt;
            else
                ans += lf*rf;
        }
        
        else if(s[k] == '^') {
            if(isTrue == true)
                ans += lt*rf + lf*rt;
            else
                ans += lf*rf + lt*rt;
        }
    }
    mp.insert({temp, ans});
    return  ans;
}

int main() {
	// your code goes here
	//mp.clear();
	string s;
	cin>>s;
	cout<<Solve(s, 0, s.length()-1, true)<<endl;
	return 0;
}
