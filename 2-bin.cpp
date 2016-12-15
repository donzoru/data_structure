#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    char c;
    int t = 0,a = 1;
    while((c=getchar())){
        if(c=='-') a = -a;
        else if(c>='0' && c<='9') t = t*10+c-'0';
        else {
            arr.push_back(a*t);
            if(c=='\n') break;
            t = 0,a = 1;
        }
    }
    cin>>a;
    sort(arr.begin(),arr.end());
    vector<int>::iterator i;
    i = lower_bound(arr.begin(),arr.end(),a);
    cout<<*(i-1)<<' ';
    i = upper_bound(arr.begin(),arr.end(),a);
    cout<<*i<<endl;
    return 0;
}
/*
-10 -2 3 10 4 6
5
*/
