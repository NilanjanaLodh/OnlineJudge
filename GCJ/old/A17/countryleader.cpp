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
        vi occ(26,0);
        int t,n,i, T,j, maxdist ,dist,l, x;
        string dummy , leader;

        cin>>T;getline(cin,dummy);
        vector<string> name;

        for(t=1;t<=T;t++)
        {
            cin>>n;getline(cin,dummy);
            name = vector<string>(n);
            for(i=0;i<n;i++)
                {
                    getline(cin,name[i]);
                }
            sort(name.begin(), name.end());

            maxdist=0;
            leader = "" ;
            for(i=0;i<n;i++)
            {
                dist=0;
                occ = vi(26,0);
                l= name[i].size();

                for(j=0;j<l;j++)
                {
                    if(name[i][j]==' ')
                        continue;

                    x = name[i][j] - 'A';
                    if(!occ[x])
                    {
                        dist++;
                        occ[x] =1;
                    }
                }

                if(dist>maxdist)
                {
                    maxdist= dist;
                    leader= name[i];
                }
            }

            cout<<"Case #"<<t<<": "<<leader<<endl;
        }
}
