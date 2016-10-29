//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

const lli inf= 9000000000000;
const lli mod= 1000000007;

int main()
{
    int nb, ng ,bp, gp, pairs = 0 ,i;
    vi b, g;
    cin>>nb;
    b = vi(nb);
    for(i=0;i<nb;i++)
        cin>>b[i];

    cin>>ng;
    g = vi(ng);
    for(i=0;i<ng;i++)
        cin>>g[i];

    sort(b.begin() , b.end());
    sort(g.begin() , g.end());

    bp=0; gp =0;

    while(gp<ng && bp<nb)
    {
        if(abs(b[bp]- g[gp]) <=1)
        {
            pairs++;
            bp++;
            gp++;
        }
        else if(b[bp] > g[gp])
            gp++;

        else
            bp++;
    }
    cout<<pairs<<endl;
}
