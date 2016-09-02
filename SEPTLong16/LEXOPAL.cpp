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
    int t,i,l;
    char s[1000000];
    scanf("%d",&t);
    char c , d;
    bool possible;
    while(t--)
    {
        possible = true;
        scanf("%s",s);
        l=strlen(s);
        for(i=0;i<(l+1)/2;i++)
        {
            c = s[i];
            d = s[l-i-1];

            if(c=='.'  && d=='.')
            {
                s[i]=s[l-i-1]='a';
            }
            else if(c=='.')
            {
                s[i]=s[l-i-1];
            }
            else if(d=='.')
            {
                s[l-i-1]=s[i];
            }
            else if(c!=d)
            {
                possible= false;
                break;
            }
        }
        if(!possible)
            printf("-1\n");

        else
            printf("%s\n",s);
    }
}
