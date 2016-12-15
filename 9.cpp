#include<bits/stdc++.h>
using namespace std;
bool mapp[26][26];
bool vis[26];
int n;
char a,b,c;
void dfs(int n)
{
    if(n+'A' ==b) return;
    for(int i=0;i<26;++i)
    {
        if(mapp[n][i] && !vis[i]){
            vis[i] = 1;
            dfs(i);
        }
    }
}

int main()
{
    int m;
    memset(mapp,0,sizeof(mapp));
    memset(vis,0,sizeof(vis));
    cin>>n;
    c = getchar();
    while((a=getchar())!='\n');
    cin>>m;
    while(m--){
        cin>>a>>b;
        mapp[a-'A'][b-'A'] = 1;
    }
    cin>>a>>b;
    dfs(a-'A');
    if(vis[b-'A']) printf("1\n");
    else printf("0\n");
    return 0;
}
