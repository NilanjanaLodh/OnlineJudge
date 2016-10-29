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

    int t,i;
    int n,aa,bb,ab, ba;
    cin>>t;
    string s,pre, suf , ans;
    while(t--)
    {
        cin>>n;
        aa = bb = ab = ba =0 ;
        pre = "" ;
        suf = "";
        while(n--)
        {
            cin>>s;
            if(s=="ab")
                ab++;

            if(s=="aa")
                aa++;

            if(s=="ba")
                ba++;

            if(s=="bb")
                bb++;
        }
        //cout<<aa<<" "<<ab<<" "<<ba<<" "<<bb<<endl;
        for(i=0;i<aa/2;i++)
        {
            pre += "aa" ;
            suf = "aa" + suf ;
        }

        for(i=0;i<min(ab,ba);i++)
        {
            pre += "ab";
            suf = "ba" + suf;
        }

        for(i=0;i<bb/2;i++)
        {
            pre += "bb" ;
            suf = "bb" + suf ;
        }

        aa = aa%2; bb = bb%2 ;
        if(aa == 1)
        {
            ans = pre + "aa" + suf ;
        }
        else if(bb ==  1)
        {
            ans = pre + "bb" + suf;
        }
        else
        {
            ans = pre + suf;
        }

        cout<<ans<<endl;

    }
    return 0;
}
