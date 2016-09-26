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

lli maximum(lli a , lli b, lli c , lli d)
{
    return maximum(maximum(a,b) , maximum(c,d));
}

lli pow(lli a, lli b)
{
    if(b==0)
        return 1;

    lli ans = pow(a,b/2);
    if(b%2==1)ans= (ans*ans)%mod;

    return ans;
}
vector<vi> a, onstack ;
vector<vi> lp;
int r, c ;
bool outofrange(int i,int j)
{
    if(i>=0 && i<r && j>=0 && j<c)
        return false;

    return true;
}

lli longest_path(int i, int j)
{
    if(outofrange(i,j))
        return 0;

    if(lp[i][j]!=-1)
        return lp[i][j];

    else
    {
        //cout<<"i , j = "<<i<<" "<<j<<endl;
        if(onstack[i][j])
            return 0;

        onstack[i][j]=1;

        if(a[i][j]==0)
            {
            onstack[i][j]= false;
            return 0;
            }
        lp[i][j] = maximum(longest_path(i,j+1) , longest_path(i+1 , j ) , longest_path(i, j-1) , longest_path(i-1 , j))  + 1;

        onstack[i][j] = 0;
        return lp[i][j];
    }
}

int main()
{
    cout<<"enter r : ";cin>>r;
    cout<<"enter c : ";cin>>c;

    a= vector<vi>(r, vi(c));
    lp= vector<vi>(r, vi(c , -1));
    onstack= vector<vi>(r, vi(c , false));

    int i, j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            cin>>a[i][j];
    }

    lli longest = 0 , tmp;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            onstack= vector<vi>(r, vi(c , false));
            tmp = longest_path(i,j);
            if(tmp>longest)
            longest = tmp;
        }
    }

    cout<<longest<<endl;
}
