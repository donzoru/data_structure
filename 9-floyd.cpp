#include<bits/stdc++.h>
using namespace std;
bool mapp[26][26];
int n;
char a,b,c;
int main()
{
    int m;
    memset(mapp,0,sizeof(mapp));
    cin>>n;
    c = getchar();
    while((a=getchar())!='\n');
    cin>>m;
    while(m--){
        cin>>a>>b;
        mapp[a-'A'][b-'A'] = 1;
    }
    cin>>a>>b;
    for(int i=0;i<26;++i)
        for(int j=0;j<26;++j)
            if(mapp[i][j])
                for(int k=0;k<26;++k)
                    if(mapp[i][j] && mapp[j][k]) mapp[i][k] = 1;

    if(mapp[a-'A'][b-'A']) printf("1\n");
    else printf("0\n");
    return 0;
}
