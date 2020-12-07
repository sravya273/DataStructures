#include <bits/stdc++.h>
using namespace std;

struct node 
{ 
    int data; 
    struct node* left;
	struct node* right; 
};

node* newNode(int k)
{
    struct node *temp = new node();
    temp->data =k;
    temp->left =NULL;
    temp->right = NULL;
    
    return temp;
}

void printInorderTraversal(node* root)
{
    if(root == NULL)
    return;
    printInorderTraversal(root->left);
    cout<<root->data<<" ";
    printInorderTraversal(root->right);
}
int convertToSumTree(node* root)
{
    if(root == NULL)
    return 0;
    int oldvalue = root->data;
    root->data = convertToSumTree(root->left)+convertToSumTree(root->right);
    return root->data +oldvalue;
}
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
  
  cout<<"Given tree is ";printInorderTraversal(root);
  cout<<endl;
  convertToSumTree(root);
  cout<<"Sum tree is"; printInorderTraversal(root); 
  return 0; 
} 
