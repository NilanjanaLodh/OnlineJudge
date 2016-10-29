//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

const lli inf= 9000000000000;
const lli mod= 1000000007;

int main()
{

    int n, m;
    cin>>n>>m;
    vi a(m);
    int i;
    for(i=0;i<m;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    lli mini=inf , tmp;
    for(i=0;(i+n-1)<m;i++)
    {
        tmp=a[i+n-1]-a[i];
        if(tmp<mini)
        mini=tmp;
    }
    cout<<mini<<endl;
    return 0;
}
