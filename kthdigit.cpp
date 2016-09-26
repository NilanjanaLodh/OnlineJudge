
//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

const lli inf= 9000000000000;
const lli mod= 1000000007;
lli digit(lli k)
{
    lli num = 9 , size =1 ;
    lli span = num*size ;

    while(k>span)
    {
        k-=span;
        num*=10; size++;

        span = num*size ;
    }
    lli whichpos = k%size ;
    lli whichnum = k/size ;
    if(whichpos==0)
    {
        whichnum--;
        whichpos = size;
    }

    lli pos = size - whichpos ;
    lli x = num/9 + whichnum ;

    lli i;
    for(i=0;i<pos;i++)
    {
        x/=10;
    }

    return x%10;
}

int main()
{
    lli k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>k;
        cout<<digit(k)<<endl;
    }
}
