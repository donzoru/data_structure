#include<bits/stdc++.h>
using namespace std;
const int M = 100;
int a[M],b[M];
void merges(int s,int mid,int e)
{
    int i=s,j=mid+1,k=s;
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i<=mid)
        b[k++] = a[i++];
    while(j<=e)
        b[k++] = a[j++];
}
void bac(int s,int e)
{
    for(int i=s;i<=e;++i)
        a[i] = b[i];
}
void divi(int s,int e)
{
    if(s<e){
        int mid = (s+e)/2;
        divi(s,mid);
        divi(mid+1,e);
        merges(s,mid,e);
        bac(s,e);
    }
}
int main()
{
    char c;
    int t = 0,k = 0;
    while((c=getchar())!='\n'){
        if(isblank(c)) {
            a[k++] = t;
            t = 0;continue;
        }else t = t*10 +c-'0';
    }
    a[k++] = t;
    divi(0,k-1);
    for(t=0;t<k;++t)
        printf("%d%c",a[t],t==k?'\n':' ');
    return 0;
}
