//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

const lli inf= 9000000000000;
const lli mod= 1000000007;

vli gs;
int n;
vli a;
vector<vli> mult;
lli goodset(lli x)
{
    if(gs[x]!=-1)
        return gs[x];

    int i;
    lli m;
    gs[x]= 1;
    for(i=0;i<mult[x].size();i++)
    {
        m = mult[x][i];
        gs[x]+= goodset(m);
    }

    return gs[x];
}
void premult()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;a[j]*a[j]<=a[i];j++)
        {
            if(a[i]%a[j] ==0)
            {
                mult[a[j]].push_back(a[i]);
            }
        }
    }
}

int main()
{

    int t;
    cin>>t;
    int i;
    lli ans;
    while(t--)
    {
        cin>>n;
        a = vli(n);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a.begin() , a.end());
        premult();
        gs= vli(750000, -1);
        ans= 0;
        for(i=0;i<n;i++)
        {
            ans += goodset(a[i]);
        }
    }
    return 0;
}
