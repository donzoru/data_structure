#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define LEN sizeof(struct node)
typedef struct node node;
struct node{
    char c;
    float p;
    node *left,*right;
};
int cmp(const void * a,const void * b)
{
    return (*(node *)a).p > (*(node *)b).p ? 1: -1;
}
int n,num;
node a[100];
char s[100];
char ans[100][100];
node * cre()
{
    node *p,*head,*t;
    int i,j=0;
    for(i=0;i<n-1;++i)
    {
        qsort(a+j,num-j,LEN,cmp);
        t = &a[j];
        p = &a[j+1];
        a[num].p = t->p+p->p;
        a[num].c = '#';
        a[num].left = t;
        a[num++].right = p;
        j+=2;
    }
    head = &a[num-1];
    return head;
}
void pre(node *head,int t)
{
    if(head){
        if(head->c!='#') {
            s[t] = 0;
            strcpy(ans[head->c-'a'],s);
            return;
        }
        s[t] = '0';
        pre(head->left,t+1);
        s[t] = '1';
        pre(head->right,t+1);
    }
}
int main()
{
    int i;
    char c;
    int has[26]={0};
    scanf("%d",&n);
    getchar();
    i = 0;
    while((c=getchar())!='\n'){
        if(isalpha(c)){
            a[i++].c = c;
            has[c-'a'] = 1;
        }
    }
    for(i=0;i<n;++i){
        scanf("%f",&a[i].p);
        a[i].left = a[i].right = NULL;
    }
    num = n;
    node *head = cre();
    pre(head,0);
    for(i=0;i<26;++i){
        if(has[i]){
            printf("The %c 's Huffman code is:%s\n",i+'a',ans[i]);
        }
    }
    return 0;
}
/*
8
abcdefgh
0.07
0.19
0.02
0.06
0.32
0.03
0.21
0.10
*/
