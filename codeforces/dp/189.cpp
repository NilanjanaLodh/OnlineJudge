//Nilanjana Lodh
#include <bits/stdc++.h>
#define ERROR (-99999)
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

int n, a , b ,  c;
vi dp;
int max_piece(int k)
{
   // cout<<"k = "<<k<<endl;

    if(k<0)
        return ERROR;
    if(k==0)
        return 0;

    if(dp[k]!=-1)
        return dp[k];

    int tmp = max(   max(max_piece(k-a) , max_piece(k-b) ) , max_piece(k-c)) ;
    if(tmp==ERROR)
        dp[k]=ERROR;

    else
        dp[k]=1+tmp;

    return dp[k];

}
int main()
{
    cin>>n>>a>>b>>c;
    dp = vi(n+1  , -1);
    cout<<max_piece(n)<<endl;
    return 0;
}
