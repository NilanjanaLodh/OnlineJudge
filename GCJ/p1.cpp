//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

const lli inf= 9000000000000;
const lli mod= 1000000007;

int r,c;
vector<vli> a;
vector<vector<bool> > m;
vector<vli> diag;
vector<vli> top;
vector<vli> lft;
lli minimum(lli a, lli b)
{
    if(a<b)return a;
    return b;

}
lli minimum(lli a , lli b, lli c)
{
    return minimum(a, minimum(b,c));
}
int main()
{
    int t,T,x,y;
    cin>>T;
    int i,j,k;
    lli sum;
    for(t=1;t<=T;t++)
    {
        cin>>r>>c>>k;
        a= vector<vli>(r+1 , vli(c+1 ,0));
        diag = vector<vli>(r+1 , vli(c+1,0));
        top = vector<vli>(r+1 , vli(c+1,0));
        lft = vector<vli>(r+1 , vli(c+1,0));
        m = vector<vector<bool> >(r+1 , vector<bool>(c+1 , false));

        while(k--)
        {
            cin>>x>>y;
            m[x+1][y+1]= true;
        }

        sum = 0;
        lli tmp;

        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(m[i][j])
                {
                    diag[i][j]= top[i][j] = lft[i][j] = 0 ;
                    a[i][j]=0;
                }
                else
                {
                    diag[i][j] = 1+ diag[i-1][j-1];
                    top[i][j] = 1 + top[i-1][j];
                    lft[i][j] = 1 + lft[i][j-1];

                    tmp = 1 + a[i-1][j-1] ;
                    a[i][j]= minimum(tmp , lft[i][j] , top[i][j]);

                    sum+=a[i][j];
                }


            }


        }


        cout<<"Case #"<<t<<": "<<sum<<endl;

    }


}
