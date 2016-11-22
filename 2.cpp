#include<bits/stdc++.h>
using namespace std;

typedef struct BinTree *bt;
struct BinTree{
    char ch;
    bt le,ri;
};

bt creat()
{
    char c;
    bt b;
    scanf("%c",&c);
    getchar();
    if(c=='*'){
        b = NULL;
    }else{
        b = (bt)malloc(sizeof(struct BinTree));
        b->ch = c;
        b->le = creat();
        b->ri = creat();
    }
    return b;
}

void pre(bt b)//root left right
{
    if(b){
        printf("%c ",b->ch);
        pre(b->le);
        pre(b->ri);
    }
}

void in(bt b)//left root right
{
    if(b){
        in(b->le);
        printf("%c ",b->ch);
        in(b->ri);
    }
}

void post(bt b)//left right root
{
    if(b){
        post(b->le);
        post(b->ri);
        printf("%c ",b->ch);
    }
}

void floor(bt b)
{
    queue<bt> zy;
    zy.push(b);
    while(!zy.empty())
    {
        bt t = zy.front();
        zy.pop();
        printf("%c ",t->ch);
        if(t->le) zy.push(t->le);
        if(t->ri) zy.push(t->ri);
    }
}
int main()
{
    bt root = creat();
    pre(root);
    printf("\n");
    in(root);
    printf("\n");
    post(root);
    printf("\n");
    floor(root);
    return 0;
}
//AB*CD***E*FGH**K***
//E B A * * D C * * * F * H G * * I * K J * * *
