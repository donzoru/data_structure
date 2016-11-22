#include<bits/stdc++.h>
using namespace std;
struct node{
    int n;
    node * next;
};
node * cre(int n)
{
    node * t = new node;
    t->n = n;
    t->next = NULL;
    return t;
}
int main()
{
    int k,a;
    node *h,*p,*t;
    p = h = NULL;
    for(int i=0;i<2;++i)
    {
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&a);
            p = h;
            if(h==NULL){
                h = cre(a);
                continue;
            }
            for(t = p; p && a>=p->n ;t=p,p=p->next);
            if(p==h)
            {
                t = cre(a);
                t ->next = h;
                h = t;
            }
            else
            {
                p = cre(a);
                p->next = t->next;
                t->next = p;
            }
        }
    }
    printf("The current List is:\n");
    p = h;
    printf("%d",p->n);
    p=p->next;
    while(p){
        printf(",%d",p->n);
        p=p->next;
    }
    printf("\n");
    return 0;
}
