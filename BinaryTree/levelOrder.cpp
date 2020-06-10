#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push
struct node 
{ 
    int data; 
    struct node* left;
	struct node* right; 
}; 
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
                        malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return(node); 
} 
void levelOrder(queue<node* > levelqueue,node* head)
{
	if(head!=NULL)
	{
		levelqueue.pb(head);
		levelqueue.pb(newNode(0));
		while(!levelqueue.empty())
		{
			node* temp = levelqueue.front();
			
			levelqueue.pop();
			if(temp->data!=0)
			{
				cout<<temp->data<<" ";
				if(temp->left!=NULL)
				levelqueue.pb(temp->left);
				
				if(temp->right!=NULL)
				levelqueue.pb(temp->right);
				
			}else if(temp->data==0 && !levelqueue.empty()){
				levelqueue.pb(newNode(0));
				cout<<endl;
			}
		}
	}
}
void printLevelOrder(node* head)
{
	queue<node* > levelqueue;
	
	levelOrder(levelqueue,head);
}




  
/* Driver program to test above functions*/
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Level Order traversal of binary tree is \n"); 
    printLevelOrder(root); 
  
    return 0; 
} 
