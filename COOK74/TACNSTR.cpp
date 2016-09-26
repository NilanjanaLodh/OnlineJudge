//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
const lli mod= 1000000007;

int main()
{
    vli le;
    string s;
    int l,i;
    lli ans;

    cin>>s;
    l = s.size();
    le = vli(l); /// le[i] gives the number of prefixes upto index i larger than or equal to s[0..i]
    ans = 0;

    le[0]='Z'-s[0] + 1;
    for(i=1;i<l;i++)
        le[i]= (    (((le[i-1] - 1)*26)%mod)  +    (1*('Z'-s[i]+1)%mod)  )%mod ;


    for(i=l-1;i>=1;i--)
    {
        ans = (ans + (le[i-1]*('Z' - s[i])%mod) )%mod;
    }
    ans = (ans + ('Z' - s[0]))%mod;
    cout<<ans<<endl;

}
