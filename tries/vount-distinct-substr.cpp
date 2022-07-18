#include<bits/stdc++.h>
using namespace std;

class Node{
    Node*links[26] = {NULL};

    public:
    bool contains(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void addNew(char ch, Node*node){
        links[ch - 'a'] = node;
    }
    Node*get(char ch){
        return links[ch - 'a'];
    }
};

int main ()
{
    int ct = 0;
    string s;
    cin>>s;

    Node*root = new Node;

    for(int i=0;i<s.length();i++)
    {
        Node*node = root;
        for(int j=i;j<s.length();j++)
        {
            if(!(node -> contains(s[j]))){
                ct++;
                node -> addNew(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    cout<<ct+1<<endl;
    return 0;
}