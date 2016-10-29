//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<bool> vb;
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
int new_fun()
{
    cout<<"Yay! .. this is so fun!"<<endl;
}

int main()
{
    int i, n;
    cin>>n;
    string s;
    lli l,ans ,j, dist;
    vi occ(26, 0);
    for(i=1;i<=n;i++)
    {
        cin>>s;
        //cout<<s<<endl;
        l= s.size();
        ans = 1;

        for(j=0;j<l;j++)
        {
            occ= vi(26,0); dist = 0 ;

            if(j!=0)
            {
                if(!occ[s[j-1]-'a'])dist++;
                occ[s[j-1]-'a'] = 1;
            }

            if(!occ[s[j]-'a'])dist++;
            occ[s[j]-'a'] = 1;

            if(j!=(l-1))
            {
                if(!occ[s[j+1]-'a'])dist++;
                occ[s[j+1]-'a'] = 1;
            }


            ans = (ans*dist) % mod;
        }

        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}

