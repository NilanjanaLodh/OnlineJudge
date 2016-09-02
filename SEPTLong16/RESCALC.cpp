//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

const int inf= 999999;
const lli mod= 1000000007;

int main()
{
    lli t,tmp, taken;
    lli n,i,j ,x;
    lli a[7]; vli counts(0);
    lli bonus[7] = {0 ,0 ,0, 1 ,2 ,4};
    lli p , maxp , maxi , coins , dist;
    bool tie;

    cin>>t;
    while(t--)
    {
        cin>>n;
        maxp=0;
        tie = false;
        for(i=0;i<n;i++)
        {
            p = 0 ; dist = 0 ;
            cin>>coins;
            p += coins;
            a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=0;
            for(j=0;j<coins;j++)
            {
                cin>>x;
                a[x]++;
            }
            counts.clear();
            for(j=1;j<=6;j++)
            {
                counts.push_back(a[j]);
            }
            sort(counts.rbegin() , counts.rend() );
            taken = 0;
            for(j=5;j>2;j--)
            {
                tmp = counts[j] - taken;
                taken += tmp;
                p += (tmp*bonus[j]);
            }
            if(p>maxp)
            {
                maxp = p;
                tie= false;
                maxi = i;
            }
            else if(p==maxp)
            {
                tie = true ;
            }
        }

        if(tie)
        {
            cout<<"tie"<<endl;
        }
        else
        {
            if(maxi==0)
                cout<<"chef"<<endl;

            else
                cout<<(maxi + 1)<<endl;
        }
    }
}
