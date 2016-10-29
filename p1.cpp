//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;


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
int px0 ,py0 ,px1, py1, m , c;
bool lies(double x, double y)
{
    if(px0 == px1)
    {
        return x==px0 ;
    }
    return (y==(m*x+ c));
}

int main()
{
    int t;
    cin>>t;
    int n;
    int x,i, y;
    bool outlier;
    while(t--)
    {
        cin>>n;
        if(n==0)
            cout<<"no"<<endl;
        else if(n==1)
        {
            cin>>x>>y;
            cout<<"no"<<endl;
        }
        else if(n==2)
        {
            cin>>x>>y;
            cin>>x>>y;
            cout<<"yes"<<endl;
        }
        else
        {
            cin>>px0>>py0;
            cin>>px1>>py1;
            if(px0==px1)
            {
                //m=inf;
                //c=inf;
            }
            else
            {
                m=double(py1-py0)/double(px1-px0);
                c= py0 - m*px0;
            }
            outlier = false;
            for(i=2;i<n;i++)
            {
                cin>>x>>y;
                if(!lies(x,y))
                    outlier = true;
            }
            if(outlier)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }

    return 0;
}
