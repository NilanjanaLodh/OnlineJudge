//Nilanjana Lodh
#include <stdlib.h>
#include <vector>
#include <iostream>
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
lli pow(lli x, lli y, lli p)
{
    lli res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


lli a, b ,n ,k;
vli ka , kb ;
vector<vli> rka  , rkb ;
lli noob()
{
    int i, j;
    lli ans =0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(((pow(i,a,k)+ pow(j,b,k))%k) == 0)
            {
                ans = (ans+1)%mod;
            }
        }
    }
    return ans;
}

int main()
{
    lli j,x,y,lx,ly,nx,ny,tx,ty,tx_, ty_;
    lli T,t,i, ans;
    cin>>T;
    lli noobans;
    for(t=1;t<=T;t++)
    {
        cin>>a>>b>>n>>k;
        noobans = noob();
        ka = vli(k);
        kb = vli(k);
        //rka.clear();
        //rkb.clear();
        rka = vector<vli>(k);
        rkb = vector<vli>(k);
        for(i=0;i<k;i++)
        {
            ka[i] = pow(i,a, k);/// (i^a) % k
           // cout<<i<<"^ "<<a<<"% "<<k<<" = "<<ka[i]<<endl;
            rka[ka[i]].push_back(i);

            kb[i] = pow(i, b, k);
           // cout<<i<<"^ "<<b<<"% "<<k<<" = "<<kb[i]<<endl;
            rkb[kb[i]].push_back(i);
        }
        ans = 0;
        for(x=0;x<k;x++)
        {
            y = (k-x)%k ;
            if(y<0)
                {
                    y = (2*k - x)%k;
                }

//            cout<<"\n\nx , y = "<<x<<" , "<<y<<endl;
            lx = rka[x].size();
            ly = rkb[y].size();
//            for(i=0;i<lx;i++)
//                cout<<rka[x][i]<<"  ";
//            cout<<endl;
//            for(j=0;j<ly;j++)
//                cout<<rkb[y][j]<<"  ";
//            cout<<endl;

            for(i=0;i<lx;i++)
            {
                for(j=0;j<ly;j++)
                {
                    nx = rka[x][i];
                    if(nx>n)tx=0;

                    else
                        tx = ((n- nx)/k   + (nx!=0));

                    ny = rkb[y][j];
                    if(ny>n) ty=0;
                    else
                        ty = (n- ny)/k   + (ny!=0);

                 //   cout<<   nx << " "<<ny<<"  : ";
                    if(nx == ny)
                        {
                            tx_ = maximum(tx-1 , 0);
                            ty_= maximum(ty-1 , 0);
                            ans = (ans + (((tx_)*ty)%mod + ((tx*(ty_))%mod))%mod)%mod  ;

                   //         cout<< ((tx-1)*ty + tx*(ty-1))<<endl;
                        }

                    else
                        {
                            ans = (ans + ((tx * ty)%mod) )%mod ;
                       //     cout<<(tx * ty)<<endl;
                        }
                }
            }

        }

        cout<<"Case #"<<t<<": "<<ans<<endl;
        if(noobans!=ans)
            {
                cout<<noobans<<endl;
                exit(EXIT_FAILURE);
            }
    }

}
