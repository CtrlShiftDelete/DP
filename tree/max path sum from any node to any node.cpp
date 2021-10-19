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
    if(root == NULL)
        return 0;
        
    int lt = Solve(root->left, result);
    int rt = Solve(root->right, result);
    
    int temp = std::max(std::max(lt, rt) + root->data, root->data);
    
    int ans = std::max(lt + rt + root->data, temp);
    
    result = max(ans , result);
    
    return temp;
}

int main() {
	// your code goes here
    struct Node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
	
	int result = INT_MIN;
	Solve(root, result);
	cout<<result<<endl;
	return 0;
}
