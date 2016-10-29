//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

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
    ans = (ans*ans)%mod;

    if(b%2==1)ans= (ans*a)%mod;

    return ans;
}
int main()
{
    int n;
    cin>>n;
    vi a(n+1);
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    vli sum(n+1);
    sum[0] = 0;
    for(i=1;i<=n;i++)
    {
        sum[i]= sum[i-1] + a[i];
    }
    int q,k;
    cin>>q;
    int it;//iterations
    while(q--)
    {
        cin>>k;
        it=(n)/(k+1);
        if(n%(k+1)!=0)
            it++;
        cout<<sum[it]<<endl;
    }
    return 0;
}
