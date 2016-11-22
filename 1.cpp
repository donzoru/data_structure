#include<bits/stdc++.h>
using namespace std;
const int M = 100;
int n;
bool mapp[M][M];
char df[M],bf[M];
bool vis[M];
void bfs()
{
    int t = 0;
    queue<int> zy;
    zy.push(0);
    while(!zy.empty())
    {
        int a = zy.front();
        zy.pop();
        vis[a] = 1;
        bf[t++] = a +'A';
        for(int i=n-1;i>=0;--i)
            if(mapp[a][i] && !vis[i]) zy.push(i);
    }
}
void dfs(int k,int deep)
{
    df[deep] = 'A'+k;
    if(deep==n-1) return;
    for(int i=0;i<n;++i)
    {
        if(mapp[k][i] && !vis[i]) {
            vis[i] = 1;
            dfs(i,deep+1);
            vis[i] = 0;
        }
    }
    return;
}

void print(char *s)
{
    for(int i=0;i<n;++i)
        printf("%c%s",s[i],((i==n-1)?"\n":"  "));
}

int main()
{
    int m;
    char a,b;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a;
    memset(mapp,0,sizeof(mapp));
    scanf("%d",&m);
    while(m--)
    {
        cin>>a>>b;
        mapp[a-'A'][b-'A'] = 1;
    }
    //dfs
    memset(vis,0,sizeof(vis));
    dfs(0,0);
    print(df);
    //bfs
    memset(vis,0,sizeof(vis));
    bfs();
    print(bf);
    return 0;
}
