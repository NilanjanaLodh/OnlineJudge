//problem URL : http://www.spoj.com/problems/PRUBALL/
// Nilanjana Lodh
// DP
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

vector< vli > DP;

lli minWorstCase(int m, int e)//m storeyed building , e eggs
{
    if(m==0)return 0;
    if(e==0)return inf;
    if(DP[m][e]!=-1)
        return DP[m][e];
    
    lli tmpmin=inf,tk;
    int k;
    for(k=1;k<=m;k++)
    {
        tk=1 + maximum(minWorstCase(k-1,e-1),minWorstCase(m-k,e));
        if(tk<tmpmin)
        {
            tmpmin=tk;
        }
    }
    DP[m][e]=tmpmin;

    return DP[m][e];

}

int main()
{
    int t,x,m,e;
    cin>>t;
    while(t--)
    {
        cin>>x;
        cin>>e>>m;
        DP= vector<vli>(m+1,vli(e+1,-1));
        cout<<x<<" "<<minWorstCase(m,e)<<endl;
    }
}
















