#include<bits/stdc++.h>
using namespace std;
struct node{
    int n;
    node * next;
};
node * head;
void print()
{
    node *p = head;
    cout<<"The current List is:"<<endl;
    while(p){
        //cout<<p->n<<(p->next)?' ':'\n';
        printf("%d%c",p->n,(p->next)?',':'\n');
        p=p->next;
    }
}
void cre(int n)
{
    node *p;
    head = p = new node;
    while(n--)
    {
        scanf("%d",&p->n);
        if(n){
            p->next = new node;
            p = p->next;
        }
        else p->next = NULL;
    }
}
void ssort(int n)
{
    node * p,*t,*k;
    int mini;
    p = head;
    while(p->next)
    {
        k = p->next;
        mini = p->n;
        t = p;
        while(k){
            if(k->n < mini){
                t = k;
                mini = k->n;
            }
            k=k->next;
        }
        t->n = p->n;
        p->n = mini;
        p = p->next;
    }
}
int main()
{
    int n;
    cin>>n;
    cre(n);
    ssort(n);
    print();
    return 0;
}
/*
5
4 20 12 7 31
*/
