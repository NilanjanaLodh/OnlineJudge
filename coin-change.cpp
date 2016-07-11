// solution to the coin change problem, DP
// problem URL : https://www.hackerrank.com/challenges/coin-change
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;
vector< vector<lli> > DP;
vector<int> den; ///the denominations
lli count_ways(int amt, int m)
{
    if(amt==0 && m==0)return 1;
    
    if(m==0) return 0;
    
    if(DP[amt][m]!=-1)///base 1 indexing
        return DP[amt][m];
    
    
    if(amt>=den[m])
        DP[amt][m] = count_ways(amt-den[m],m) + count_ways(amt,m-1);
    
    else 
        DP[amt][m] = count_ways(amt,m-1);
    
    return DP[amt][m];
}
int main() 
{
     int n,m;
    cin>>n>>m;
    den = vector<int> (m+1);
    int i;
    for(i=1;i<=m;i++)
    {
        cin>>den[i];    
    }
    DP=vector<vector<lli> >(n+5,vector<lli>(m +5 , -1));
    cout<<count_ways(n,m)<<endl;
    return 0;
}

