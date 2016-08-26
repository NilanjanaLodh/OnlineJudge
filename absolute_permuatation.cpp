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
    int t,i;
    cin>>t;
    int n, k ,x, blocksize ;
    while(t--)
    {
        cin >>n >> k;
        blocksize = 2*k;
        if(blocksize!=0  && n%(blocksize)!=0)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            for(i=0;i<n; i++)
            {
                if(blocksize == 0)
                {
                    x= (i + 1);
                }

                else
                    x = ((i+k)%(blocksize)) + (i/blocksize)*blocksize + 1 ;

                cout<<x<<" ";
            }
            cout<<endl;
        }

    }
}

