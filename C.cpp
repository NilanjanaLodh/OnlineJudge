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
vi populate(int n)
{
    vi a= vi(n+1);
    int i;
    for(i=1;i<=n;i++)
    {
        a[i]=i;
    }
    return a;
}
void swapVal(int &a , int &b)
{
    int t= a;
    a= b;
    b =t;
}
int main()
{
    int t,i,start,n,k;
    cin>>t;

    vi a;
    while(t--)
    {
        cin>>n>>k;
        if(2*k > n)
        {
            cout<<"-1"<<endl;
        }

        else
        {
            //cout<<"hi"<<endl;
            a = populate(n);
            if(k>0)
             {
                for(start = 1;(start-1)+2*k<=n ; start+=(2*k) )
                {
                    //cout<<"start "<<start<<endl;
                    for(i=start;i<=(start-1)+k;i++)
                    {
                       // cout<<"     swapping "<<i<<" , "<<i+k<<endl;
                        swapVal(a[i],a[i+k]);
                    }
                }
                //cout<<"last effects\n";
                if(n%(2*k) != 0)
                {
                    sort(a.begin()+n-2*k + 1 , a.end());
                    for(i=n-2*k + 1 ;i<=(n-k);i++)
                    {
                        //cout<<"     swapping "<<i<<" , "<<i+k<<endl;
                        swapVal(a[i],a[i+k]);
                    }
                }
            }
            for(i=1;i<=n;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }


    }
    return 0;
}


