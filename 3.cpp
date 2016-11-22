#include<bits/stdc++.h>
using namespace std;
char sta[1000];
char s[1000];
bool ok()
{
    int t,i;
    int n =strlen(s);
    t = n/2;
    for(i=0;i<t;++i)
        sta[i] = s[i];
    if(n & 1) i = t+1;
    for(;s[i];++i)
        if(s[i]!=sta[--t]) return 0;
    return 1;
}
int main()
{
    cin>>s;
    if(ok()) printf("1\n");
    else printf("0\n");
    return 0;
}
