#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int Solve(Node* root, int &result) {
    //base condition
    if(root ==  NULL)
        return 0;
    
    //default calculations ---- same everywhere
    int lt = Solve(root->left, result);
    int rt = Solve(root->right, result);
    
    int temp = std::max(lt , rt) + 1;
    
    int ans = std::max(temp , 1+lt+rt);
    
    result = std::max(result, ans);
    
    return temp;
}

int main() {
	// your code goes here
	
	struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
	
	int result = INT_MIN;
	Solve(root, result);
	cout<<result<<endl;
	return 0;
}
