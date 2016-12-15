#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[100];
    int a,b,n,t;
    memset(num,0,sizeof(num));
    cin>>n;
    while(n--){
        cin>>t;
        ++num[t];
    }
    cin>>a>>b;
    for(t=a;t<=b;++t)
        while(num[t]--)
            cout<<t<<' ';
    return 0;
}
