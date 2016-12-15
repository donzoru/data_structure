#include<bits/stdc++.h>
using namespace std;
const int M = 50;
int n,t;
int mapp[M][M];
bool vis[M];
void dfs(int k)
{
    vis[k] = 1;
    for(int i=0;i<n;++i){
        if(mapp[k][i] && !vis[i]){
            ++t;
            dfs(i);
        }
    }
}
char s[M];
int main()
{
    scanf("%[^:]:%d\n",s,&n);
    scanf("%[^:]:%d\n",s,&t);
    scanf("%[^\n]",s);
    memset(mapp,0,sizeof(mapp));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>mapp[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;++i){
        t = 1;
        dfs(i);
        memset(vis,0,sizeof(vis));
        if(t==n){
            ans = i;
        }
    }
    cout<<"Found a root vertex:"<<ans<<endl;
    return 0;
}
/*
please input the DAG_Graph Vertex number:4
please input the DAG_Graph arc number:4
please input the DAG_Graph adjacency matrix:
0 1 1 0
0 0 0 1
0 0 0 1
0 0 0 0
*/
