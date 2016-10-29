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
    int t,i;
    cin>>t;
    lli n, k ,s ,tmp , excess;
    while(t--)
    {
        cin>>n>>k;
        s=0;
        for(i=0;i<n;i++)
        {
            cin>>tmp;
            s+=tmp;
        }
        excess = s - k;
        if(excess>=0 && excess<n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
