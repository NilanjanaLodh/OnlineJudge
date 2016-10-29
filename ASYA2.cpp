//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef bitset<26> bitvec;
const lli inf= 9000000000000;
const lli mod= 1000000007;

lli bit_vectorize(char *s)
{
    bitvec bv;
    int l=strlen(s);
    int i;
    for(i=0;i<l;i++)
    {
        bv[s[i]-'A']=1;
    }

    return bv.to_ulong();
}

map<lli,lli> setA, setB;
int main()
{
    int i,n1, n2;
    scanf("%d",&n1);
    scanf("%d", &n2);
    char s[1009];
    lli tmp;
    for(i=1;i<=n1;i++)
    {
        scanf("%s",s);
        tmp=bit_vectorize(s);
        setA[tmp]++;
    }

    for(i=1;i<=n2;i++)
    {
        scanf("%s",s);
        tmp=bit_vectorize(s);
        setB[tmp]++;
    }

    map<lli, lli>::iterator a , b;
    lli count =0 ;

    for(a=setA.begin();a!=setA.end();a++)
    {
        for(b=setB.begin();b!=setB.end();b++)
        {
            if((a->first|b->first) == ((1<<26)-1))
            {
                count += a->second * b->second ;
            }
        }
    }

    cout<<count<<endl;


}
