#include<bits/stdc++.h>
using namespace std;
struct node  {
     char c;
     node * left,*right;
};
char ch;
node * cre()
{
    node * p = 0;
    char c;
    c = getchar();
    if(c!='#' && c!='\n')
    {
        p = new node;
        p->c = c;
        p->left = cre();
        p->right = cre();
    }
    return p;
}
node * del(node * head)
{
    if((head->c) == ch) {
        free(head);
        return 0;
    }
    if(head->left) head->left = del(head->left);
    if(head->right) head->right = del(head->right);
    return head;
}
void pre(node * head)
{
    if(head){
        cout<<head->c;
        pre(head->left);
        pre(head->right);
    }
}
int main()
{
    node * head = cre();
    cin>>ch;
    head = del(head);
    pre(head);
    return 0;
}
/*
ABC##D##C#F##
C
*/
