#include<bits/stdc++.h>
using namespace std;
struct node{
    char c;
    node * left,* right;
};
node * cre()
{
    char c;
    node * p = 0;
    c = getchar();
    if(c!='\n' && c!=' '){
        p = new node;
        p->c = c;
        p->left = cre();
        p->right = cre();
    }
    return p;
}
void dfs(node * head)
{
    if(head==NULL) return;
    cout<<head->c<<' ';
    dfs(head->left);
    dfs(head->right);
}
void bfs(node * head)
{
    queue<node *> q;
    q.push(head);
    while(!q.empty())
    {
        head = q.front();
        cout<<head->c<<' ';
        q.pop();
        if(head->left)
            q.push(head->left);
        if(head->right)
            q.push(head->right);
    }
}
int main()
{
    node* head = cre();
    dfs(head);
    cout<<endl;
    bfs(head);
    return 0;
}
