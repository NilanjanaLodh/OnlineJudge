//Nilanjana Lodh
#include <bits/stdc++.h>
#include <sstream>
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
vector< vector<double> > p;
int n,m;
double prob(int a , int b , int e)
{
    
    if(a<0 or b<0 or e<=0)
        return 0;
    
    if(a==0 && b==0)
        return 1;

    if(p[a][b]!=-1)
        return p[a][b];

    double ans=0;
    ans += (double)(a)/double(a+b) * prob(a-1 , b , e+1);
    ans += (double)(b)/double(a+b) * prob(a , b-1 , e-1);

    p[a][b] = ans;
    //cout<<" p "<<a<<" "<<b<<" "<<e<<" = "<<ans<<endl;
    return ans;

}

double prob(int a, int b)
{
    return double(a)/double(a+b) * prob(a-1 , b , 1);
}
int main()
{
    
    int T, i , t;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n>>m;
        p = vector< vector<double> >(n+1 , vector<double> (m+1 , -1));
        cout<<"Case #"<<t<<": ";
        printf("%.6f\n",prob(n,m));
        
    }
    return 0;
}
