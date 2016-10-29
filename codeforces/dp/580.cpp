//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

int main()
{
    int n;
    cin>>n;
    int i, x , prev = 0 , streak = 0 , max_streak = 0;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x>=prev)
        {
            streak++;
        }
        else
        {
            max_streak = max(max_streak , streak);
            streak = 1;
        }
        prev=x;
    }
    max_streak= max(max_streak, streak);
    cout<<max_streak<<endl;

    return 0;
}
