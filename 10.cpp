#include<bits/stdc++.h>
using namespace std;
struct node {
    char c;
    node *left,*right;
};
node * cre()
{
    node * p = 0;
    char c;
    c = getchar();
    getchar();
    if(c!='*'){
        p = new node;
        p ->c = c;
        p ->left = cre();
        p ->right = cre();
    }
    return p;
}
void bfs(node *head)
{
    queue<node *> q;
    q.push(head);
    while(!q.empty())
    {
        head = q.front();
        q.pop();
        cout<<head->c<<' ';
        if(head->left)
            q.push(head->left);
        if(head->right)
            q.push(head->right);
    }
}
int main()
{
    node * head = cre();
    bfs(head);
    return 0;
}
