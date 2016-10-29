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
    int k,r,i,x;
    cin>>k>>r;
    for(i=1;i<=10;i++)
    {
        x=(k*i)%10;
        if(x==0 or x==r)
            {
                cout<<i<<endl;
                break;
            }
    }

    return 0;
}
