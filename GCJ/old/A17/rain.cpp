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
    int h[54][54];
    int maxl[54][54] , maxr[54][54] , maxup[54][54] , maxdown[54][54];
    int r,c,i,j;
    int t, T;
    int ans , bound;

    cin>>T;

    for(t=1;t<=T;t++)
    {
        ans=0;
        cin>>r>>c;
        for(j=0;j<=c+1;j++)
        {
            h[0][j]=0;maxup[0][j]=0;
            h[r+1][j]=0;maxdown[r+1][j]=0;
        }

        for(i=0;i<=r+1;i++)
        {
            h[i][0] =0;maxl[i][0]=0;
            h[i][c+1] =0;maxr[i][c+1]=0;
        }

        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                cin>>h[i][j];
            }
        }

        ///maxl
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                maxl[i][j]=max(maxl[i][j-1] , h[i][j-1]);
            }
        }

        ///maxr
        for(i=1;i<=r;i++)
        {
            for(j=c;j>=1;j--)
            {
                maxr[i][j]=max(maxr[i][j+1] , h[i][j+1]);
            }
        }

        ///maxup
        for(j=1;j<=c;j++)
        {
            for(i=1;i<=r;i++)
            {
                maxup[i][j]=max(maxup[i-1][j] , h[i-1][j]);
            }
        }

        ///maxdown
        for(j=1;j<=c;j++)
        {
            for(i=r;i>=1;i--)
            {
                maxdown[i][j]=max(maxdown[i+1][j] , h[i+1][j]);
            }
        }

        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                bound = min (  min(maxl[i][j] , maxr[i][j])     ,  min(maxup[i][j] , maxdown[i][j]));
                cout<<i<<" "<<j<<" "<<maxl[i][j]<<" "<<maxr[i][j]<<" "<<maxup[i][j]<<" "<<maxdown[i][j]<<" : "<<bound<<endl;
                if(bound>h[i][j])
                {
                    ans += (bound - h[i][j]);
                    cout <<"        increased "<<(bound - h[i][j])<<endl;
                }
            }
        }

        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}

