//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

const lli inf= 9000000000000;
const lli mod= 1000000007;
int main()
{
    int t,l,i;
    char x[100009];
    scanf("%d", &t);
    lli a[2];
    int d;
    while(t--)
    {
        scanf("%s",x);
        l= strlen(x);
        a[0]=0;a[1]=0;
        for(i=0;i<l;i++)
        {
            d=x[i] - '0' ;
            a[d]++;
        }
        if(a[0]==1 || a[1]==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
