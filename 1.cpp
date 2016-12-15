#include<bits/stdc++.h>
using namespace std;
struct node{
    int n;
    node * l ,* r;
}nod[1000],*root;
int num,n;
node * bui(int k)
{
    node * p = &nod[num++];
    p->l = p->r = NULL;
    p->n = k;
    return p;
}
void ins(int k)
{
    node *p = root,*t =NULL;
    while(p){
        t = p;
        if(k > p->n) p = p->r;
        else if(k < p->n) p = p->l;
        else break;
    }
    if(p==NULL) {
        if(t->n > k) t->l = bui(k);
        if(t->n < k) t->r = bui(k);
    }
}
int sea0(int k)
{
    node * p = root,* t = NULL;
    while(p){
        t = p;
        if(p->n >=k) p = p->l;
        else p = p->r;
    }
    return t->n;
}
int sea1(int k)
{
    node * p = root,* t = NULL;
    while(p){
        t = p;
        if(p->n <=k) p = p->r;
        else p = p->l;
    }
    return t->n;
}

int main()
{
    num = 0;
    int a;
    cin>>n>>a;
    root = bui(a);
    while(--n){
        cin>>a;
        ins(a);
    }
    cin>>a;
    cout<<"a="<<sea0(a)<<endl<<"b="<<sea1(a)<<endl;
    return 0;
}
/*
3
3 2 4
3
*/
