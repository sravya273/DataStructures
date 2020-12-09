#include <bits/stdc++.h>
using namespace std;

struct trienode 
{ 
    struct trienode *children[26];
    bool endOfWord;
};

struct trienode * newnode()
{
    struct trienode *newnode =  new trienode();
    for(int i=0;i<26;i++)
    {
        newnode->children[i]=NULL;
    }
    return newnode;
}

void insertIntoTrie(struct trienode *root, string word)
{
    struct trienode *temp = root;
    for(int i=0;i<word.length();i++)
    {
        if(!temp->children[word[i]-'a'])
        {
            temp->children[word[i]-'a']= newnode();
        }
        temp=temp->children[word[i]-'a'];
    }
    temp->endOfWord = true;
}

bool searchTrie(struct trienode *root, string word)
{
    struct trienode *temp = root;
    for(int i=0;i<word.length();i++)
    {
        if(!temp->children[word[i]-'a'])
        {
            return false;
        }
        temp=temp->children[word[i]-'a'];
    }
    return (temp!=NULL && temp->endOfWord);
}

int main()
{
    int n;
    cin>>n;
    string s;
    struct trienode *root= newnode();
    while(n--)
    {
        cin>>s;
        insertIntoTrie(root,s);
    }
    if(searchTrie(root,"kiran"))
    {
        cout<<"Given word is present in the trie"<<endl;
    }
    else
    {
        cout<<"Given word is not present in the trie"<<endl;
    }
}
