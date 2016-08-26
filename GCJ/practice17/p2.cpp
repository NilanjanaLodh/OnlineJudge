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
    int t, i ,j , l ;
    cin>>t;
    lli k;
    int n;
    lli a[1010] , b[1010] , c[1010] , d[1010] ;
    lli ans=0;
    map<lli , lli > m;
    for(i=1;i<=t;i++)
    {

        m.clear();
        ans =0;
        cin>>n>>k;

        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(j=0;j<n;j++)
        {
            cin>>b[j];
        }
        for(j=0;j<n;j++)
        {
            cin>>c[j];
        }
        for(j=0;j<n;j++)
        {
            cin>>d[j];
            d[j] = d[j] ^ k;

        }

        for(j=0;j<n;j++)
        {
            for(l=0;l<n ; l++)
            {
                m[a[j]^b[l]]++;
            }
        }
        lli x;
        for(j=0;j<n;j++)
        {
            for(l=0;l<n;l++)
            {
                x = c[j] ^ d[l];
                if(m.find(x)!=m.end())
                {
                    ans += m[x];
                }
            }
        }

        cout<<"Case #"<<i<<": "<<ans<<endl;

    }
}
