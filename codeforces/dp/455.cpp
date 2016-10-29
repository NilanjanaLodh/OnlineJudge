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
int n;
vli dp;
vli f;
lli max_score(lli i)
{
    if(i<=0)
        return 0;

    if(dp[i]!=-1)
        return dp[i];

    dp[i] = maximum(max_score(i-1) , max_score(i-2) + f[i]*i);
    return dp[i];
}
int main()
{
    cin >> n;
    int x;
    dp = vli(100001,-1);
    f= vli(100001, 0);

    int i;

    for(i=0;i<n;i++)
    {
        cin>>x;
        f[x]++;
    }

    cout<<max_score(100000)<<endl;
    return 0;
}
