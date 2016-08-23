//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

int n;
typedef bitset<510> bitvec ;
bitvec neigh[30][510];
/**
    neigh[tpow][node] answers the question ..
    if we start from 'node' after time , 2^tpow , whom will the message reach
**/

void extrapolate(bitvec &next ,const bitvec& prev ,int pow2)
{
    /**
        This function extrapolates the bitvector prev to what it wil after time t^pow2
        and stores the value in next


    **/
    bitvec bv(prev);
    int i;
    next.reset();
    for(i=0;i<n;i++)
    {
        if(bv[i])
            next |= neigh[pow2][i] ; /// the peeps who recieve the message becuse number i forwards it.
    }

}

void precalculate()
{
    // assumption : neigh[0][ : ] already calculated

    int tpow, node;
    for(tpow =1 ; tpow<30 ; tpow++)
    {
        for(node=0; node<n ;node++)
        {
            extrapolate(neigh[tpow][node],neigh[tpow-1][node],tpow-1); /// this is the DP statement
        }
    }
}

int main()
{
    cin>>n;
    int node,pos;
    int x;
    for(node=0;node<n;node++)
    {
        for(pos=0;pos<n;pos++)
        {
            cin>>x;

            if(x)
                neigh[0][node][pos] = 1;
        }
    }

    precalculate();

    int t, m , bit , p;
    cin >> m;
    int ct;
    while(m--)
    {
        p = 0 ; /// this is the power of 2
        cin>>t>>x;  x--; // they give the input in base 1 indexing

        // t : after t time
        // x : starting position
        bitvec ans;
        ans[x] = 1; // at time 0 , only x has the message
        while(t>0)
        {
            bit = t%2;
            if(bit)
                extrapolate(ans,ans, p);

            t/=2;p++;
        }
        ct = ans.count();
        cout<<ct<<endl;
        if(ct==0)
            cout<<-1<<endl;

        else
        {
            for(pos=0; pos<n && ct>0 ; pos ++ )
                {
                    if(ans[pos])
                    {
                        ct--;
                        cout<<(pos+1)<<" ";
                    }
                }

            cout<<endl;
        }

    }
}
