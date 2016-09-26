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
    int l,i,j;
    vi occ(26,0);
    string s;
    cin>>s;
    l = s.size();
    for(i=0;i<l;i++)
    {
        occ[s[i] - 'a'] = 1;
    }
    int n;
    bool flag;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        l=s.size();
        flag=true;
        for(j=0;j<l;j++)
        {
            if(!(occ[s[j] - 'a']))
                {
                    flag= false;
                    break;
                }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

}
