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

int n;
vi pointer;
int pos;
vi a;
vector<vi> num;
vi seq;
lli total;
bool possible(int tpos , vi tpointer)
{
    if(tpos == total)
        return true;
    bool flag =false;
    int i;
    vi tpointer1 = tpointer;
    for(i=0;i<n;i++)
    {
        if(i!=0) tpointer1[i-1] = tpointer[i-1]; ///undo last move
        //tpointer1 = tpointer;
        if(tpointer[i]<a[i]  && seq[tpos]==num[i][tpointer[i]])
        {
            tpointer1[i]++ ;
            //cout<<" upddate "<<i<<" "<<tpointer1[i]<<endl;
            if(possible(tpos+1 , tpointer1))
                return true;
        }
    }

    return false;
}
int main()
{
    int t,i,j,x;
    cin>>t;
    bool flag;
    while(t--)
    {
        total =0 ;
        pos =0;
        cin>>n;
        if(n==1)
        {
            int ta;
            cin>>ta;
            vi tnum(ta);
            for(i=0;i<ta;i++)
            {
                cin>>tnum[i];
            }
            flag = true;
            for(i=0;i<ta;i++)
            {
                cin>>x;
                //cout<<"_____"<<endl;
                //cout<<x<<endl;
                //cout<<tnum
                if(x!= tnum[ta - 1 -i])
                    flag=false;

            }
            if(flag)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

        }///end if
        else
        {
            a= vi(n);/// the length of each stack
            pointer = vi(n, 0);/// the pointer to first pos of each stack

            num = vector<vi>(n,vi(0)); /// the actual stack numbers
            for(i=0;i<n;i++)
            {
                cin>>a[i];
                total += (lli)a[i] ;
                for(j=0;j<a[i];j++)
                {
                    cin>>x;
                    num[i].push_back(x);
                }
            }///i

           // cout<<"total is "<<total<<endl;
            seq= vi(total);
            for(i=total-1;i>=0;i--)
            {
                cin>>seq[i];
              //  cout<<seq[i]<<endl;
            }



            flag = possible(0, pointer);

            if(flag)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            }
    }///t
}
