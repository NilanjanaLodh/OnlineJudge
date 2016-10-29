//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

const lli inf= 9000000000000;
const lli mod= 1000000007;

int k;
vli input;
lli minadd(const vli &days ,const lli &actual_index=0)
{
    
    if(days.size() <= 1)
    {
        return 0;
    }
    cout<<"first two are :"<<endl;
    cout<<days[0]<<" "<<days[1]<<endl;
    lli base = days[1];
    vli arg = vli(days.begin()+1, days.end());
    lli req = k - (days[0] + days[1]);//this amount will be added to days[1]
    if(req<=0)
        return minadd(arg , actual_index+1);

    lli added;
    lli tmpmin=inf;
    for(added = req ; (added+days[1])<=k ; added++)
    {
        arg[0]=base + added;
        if(tmpmin > added + minadd(arg))
        {
            tmpmin = added + minadd(arg,actual_index + 1);
        }

    }

    return tmpmin;
}
int main()
{
    
    lli n,i;
    cin>>n>>k;
    input= vli(n);
    for(i=0;i<n;i++)
        cin>>input[i];
    
    vli arg = vli(input.begin() , input.end());
    cout<<minadd(arg, 0)<<endl;
    for(i=0;i<n;i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}
