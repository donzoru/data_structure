#include<bits/stdc++.h>

using namespace std;
int main()
{
    deque <int> z;
    int n,a,l,r;
    cin>>n>>a;
    z.push_back(a);
    l = r = a;
    --n;
    while(n--)
    {
        cin>>a;
        int mid = (l+r)/2;
        if(a<mid) z.push_front(a),l=a;
        else z.push_back(a),r=a;
    }
    deque <int>::iterator i;
    for(i=z.begin();i!=z.end();++i)
        cout<<*i<<' ';
    return 0;
}
