//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

const lli inf= 9000000000000;
const lli mod= 1000000007;
lli minimum(lli a, lli b)
{
    if(a<b)return a;
    return b;
}

lli maximum(lli a, lli b)
{
    if(a>b)return a;
    return b;
}

lli pow(lli a, lli b)
{
    if(b==0)
        return 1;

    lli ans = pow(a,b/2);
    if(b%2==1)ans= (ans*ans)%mod;

    return ans;
}
int main()
{
    lli t,x;
    lli T, l, r;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>l>>r;
        x=minimum(l,r);
        x= (x*(x+1)/2);
        cout<<"Case #"<<t<<": "<<x<<endl;
    }
}
