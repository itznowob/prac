#include<bits/stdc++.h>
using namespace std;
struct tree_node{
    int val;
    tree_node *left, *right;
    tree_node(int x) : val(x), left(nullptr), right(nullptr) {}
};
void in(tree_node*& root, int x){
    if (!root){ 
        root = new tree_node(x);
        return;
    }
    if (x < root->val)
        in(root->left, x);
    else
        in(root->right, x);
}
void pre(tree_node* root){
    if (!root) return;
    cout << root->val << " ";
    pre(root->left);
    pre(root->right);
}
void in(tree_node* root){
    if (!root) return;
    in(root->left);
    cout << root->val << " ";
    in(root->right);
}
void post(tree_node* root){
    if (!root) 
	return;
    post(root->left);
    post(root->right);
    cout << root->val << " ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    tree_node* root = nullptr;
    while (ss >> x)
        in(root, x);
    string order;
    cin >> order;
    if (order == "pre")
        pre(root);
    else if (order == "in")
        in(root);
    else if (order == "post")
        post(root);
}
