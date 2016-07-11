#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
vector<vli> DP;
vi size;
vi value;
lli maximum(lli a, lli b)
{
    return (a>b)?a:b;
}
lli maxval(int capacity, int index)
{
    if(capacity==0 || index==0)
        return 0;

    if(DP[capacity][index]!=-1)
        return DP[capacity][index];
    
    if(size[index]<=capacity)
     DP[capacity][index]= maximum(maxval(capacity,index-1),value[index] + maxval(capacity-size[index],index-1));
    
    else
        DP[capacity][index]=maxval(capacity,index-1);

    return DP[capacity][index];
}

int main()
{
    int capacity,n;
    cin>>capacity>>n;

    size=vi(n+1);
    value=vi(n+1);

    int i;
    for(i=1;i<=n;i++)
    {
        cin>>size[i]>>value[i];
    }
    DP=vector<vli>(capacity+1,vli(n+1,-1));
    cout<<maxval(capacity,n)<<endl;
    
}
