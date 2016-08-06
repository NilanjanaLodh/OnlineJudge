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
    int t;
    lli r, c;
    cin>>t;
    bool win;
    while(t--)
    {
        cin>>r>>c;
        if(r==1 || c==1)
            win =( maximum(r,c)-1 ) % 2;

        else
        {
            win = r%2==0 || c%2==0 ;
        }

        if(!win)
            cout<<"No"<<endl;
 
        else
            cout<<"Yes"<<endl;
    }
}
 
