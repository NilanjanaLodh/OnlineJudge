//Nilanjana Lodh
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

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
    ans = (ans*ans)%mod;

    if(b%2==1)ans= (ans*a)%mod;

    return ans;
}
map <string, int> vocab;
int v;
string sent;
int l; //length of string sent

vi dp;
int count(int start)
{
    if(start>=l) return 1;

    if(dp[start]!=-1)
        return dp[start];

    int end;
    dp[start] = 0;

    string prefix;
    int prefix_l = 0;
    for(prefix_l = 1 ; (start+prefix_l-1 < l) && (prefix_l<=20) ; prefix_l++)
    {
        prefix= sent.substr(start,prefix_l);
        sort(prefix.begin(),prefix.end());
        //cout<<"prefix is "<<prefix<<endl;
        map<string , int>::iterator it = vocab.find(prefix);
        if(it !=vocab.end())
            dp[start] = (dp[start] + (it->second)*count(start+prefix_l) % mod )%mod;
//        else
//            cout<<"  .. not found!"<<endl;
    }
    return dp[start];

}
int main()
{

    int T, i , t;
    cin>>T;
    int s;// number of sentences
    string x,y;
    for(t=1;t<=T;t++)
    {
        cin>>v>>s;
        //cout<<"hi"<<endl;
        vocab.clear();
        for(i=0;i<v;i++)
        {
            cin>>x;
            sort(x.begin(), x.end());
            //cout<<x<<endl;
            vocab[x]++;
        }
        cout<<"Case #"<<t<<": ";
        for(i=0;i<s;i++)
        {
            cin>>sent; l = sent.size();
            dp = vi(l+1 , -1);
            cout<<count(0)<<" ";
        }

        cout<<endl;

     }
    return 0;
}
