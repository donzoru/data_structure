#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct node{
    int n;
    node *l,*r;
}nod[1000],*root;
int num;
node *bui()
{
    node *p = NULL;
    int n;
    cin>>n;
    getchar();
    if(n==-1){
        return p;
    }
    p = &nod[num++];
    p ->n = n;
    p->l = bui();
    p->r = bui();
    return p;
}
vector<int> a;
void in(node * root)
{
    if(root){
        in(root->l);
        a.push_back(root->n);
        in(root->r);
    }
}
bool ok()
{
    int t = a[0];
    for(int i=1;i<a.size();++i){
        if(a[i]<t) return 0;
        t = a[i];
    }
    return 1;
}
int main()
{
    num = 0;
    root = bui();
    a.clear();
    in(root);
    if(ok()) puts("YES");
    else puts("NO");
    return 0;
}
//17,9,-1,-1,22,-1,-1
