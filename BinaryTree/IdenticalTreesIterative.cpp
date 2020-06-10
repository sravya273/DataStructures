#include <bits/stdc++.h>
using namespace std;

struct bnode
{
    int data;
    struct bnode *left;
    struct bnode *right;
};

void printInorder(struct bnode* node) 
{ 
    if (node == NULL) 
        return; 
  
    printInorder(node->left); 
    cout << node->data << " "; 
    printInorder(node->right); 
} 

struct bnode* newNode(int i)
{
    struct bnode *temp =new (struct bnode);
    temp->data=i;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
    
}
int areIdentical(struct bnode* a, struct bnode* b)
{
   if(a==NULL && b==NULL)
   return 1;
   if(a==NULL && b!=NULL)
   return 0;
   if(a!=NULL && b==NULL)
   return 0;
   queue<bnode *>q1;
   queue<bnode *>q2;
   while(!q1.empty() && !q2.empty())
   {
       bnode *n1=q1.front();
       bnode *n2=q2.front();
       
       if(n1->data != n2->data)
       return 0;
       q1.pop();
       q2.pop();
       if(n1->left && n2->left)
       {
           q1.push(n1->left);
           q2.push(n2->left);
       }
       else if (n1->left || n2->left)
       return 0;
       if(n1->right && n2->right)
       {
           q1.push(n1->right);
           q2.push(n2->right);
       }
       else if (n1->right || n2->right)
       return 0;
       
   }
    return 0;
}

int main()
{
    bnode *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
    printInorder(root1);
    cout<<endl;
    bnode *root2 = newNode(1); 
    root2->left = newNode(2); 
    root2->right = newNode(3); 
    root2->left->left = newNode(4); 
    // root2->left->right = newNode(5); 
    printInorder(root2);
    cout<<endl;
    areIdentical(root1, root2)? cout << "Identical" : cout << "Not Identical";
}
