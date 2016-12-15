#include<bits/stdc++.h>
using namespace std;
int a[100];
int n,k,ans;
void bin_sea(int l,int r)
{

    if(ans || l>r) return;
    int m = l + r >> 1;
    if(a[m]==k) {
        ans = m;
        return;
    }
    if(l==r) return;
    bin_sea(l,m-1);
    bin_sea(m+1,r);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    cin>>k;
    ans = 0;
    bin_sea(1,n);
    if(ans) cout<<ans<<endl;
    else cout<<0<<endl;
    return 0;
}
/*
5
33 29 25 20 12
29
9
33 29 20 12 9 8 7 2 0
100
*/
