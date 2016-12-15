#include<bits/stdc++.h>
using namespace std;
const int M = 100;
int n,m;
string s;
bool dia[M][M];
int top[M],ind[M];
int main()
{
    scanf("%d,%d\n",&n,&m);
    cin>>s;
    int a,b;
    memset(dia,0,sizeof(dia));
    memset(ind,0,sizeof(ind));
    while(m--){
        scanf("%d,%d",&a,&b);
        ++a,++b;
        dia[a][b] = 1;
        ind[b]++;
    }
    a = 0;
    for(int i=1;i<=n;++i)
        if(ind[i]==0) top[a++] = i;
    for(int i=0;i<a;++i)
    {
        b = top[i];
        for(int j=1;j<=n;++j){
            if(dia[b][j]){
                if(--ind[j]==0)
                    top[a++] = j;
            }
        }
    }
    for(int i=0;i<n;++i)
        printf("%c,%d;",s[i],top[i]);
    return 0;
}
/*
4,4

abcd

0,1

0,2

1,3

2,3
*/
