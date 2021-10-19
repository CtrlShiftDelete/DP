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
    
    int temp = std::max(lt, rt) + root->data;
    
    int ans = std::max(lt + rt + root->data, temp);
    
    result = max(ans , result);
    
    return temp;
}

int main() {
	// your code goes here
    struct Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
	
	int result = INT_MIN;
	Solve(root, result);
	cout<<result<<endl;
	return 0;
}
