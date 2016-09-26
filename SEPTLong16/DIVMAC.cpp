//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

const lli inf= 9000000000000;
const lli mod= 1000000007;

bool isprime[1000006];
lli LPD[1000006];

lli maximum(lli a , lli b)
{
    if(a>b)return a;
    return b;
}
void precalc(lli n=1000000)
{
    memset(isprime, true , sizeof(bool)*(n+1));

    lli p,i;
    for(i=1;i<=n;i++)
    LPD[i]= i;

    for(p=2;p*p<=n;p++)
    {
        if(isprime[p])
        {
            for(i=p*p;i<=n;i+=p)
            {
                if(isprime[i]==true)
                {
                    isprime[i]=false;
                    LPD[i]= p;
                }
            }
        }
    }

//    for(i=0;i<=n;i++)
//    {
//        cout<<i<<" : "<<LPD[i]<<endl;
//    }
}

lli a[1000006];
lli n; /// number of elements
lli tree[4000909];

void build(lli root=1, lli left = 0, lli right = (n-1))
{
    if(left==right)
    {
        tree[root]= LPD[a[left]];
    }

    else
    {
        lli mid = (left + right )/2 ;
        build(2*root , left , mid);
        build(2*root + 1 , mid+1 , right);

        tree[root]= maximum(tree[2*root] , tree[2*root + 1]);
    }
}

lli query(lli start, lli end , lli root= 1 , lli left = 0, lli right = (n-1))
{
    if(end<left || start>right)
        return 0;

    if(left<= start && end<=right)
        return tree[root];

    else
    {
        lli mid = (left + right ) / 2;
        return maximum(query(start, end , 2*root , left , mid) , query(start, end , 2*root + 1 , mid + 1 , right ));
    }
}

void update(lli start , lli end , lli root = 1 , lli left= 0 , lli right = (n-1))
{
    /// range update ..
    if(end<left || start> right)
        return ;
    /// for evry no. in start to end .. divide it by the lpd .. you get a new number a'[i]  ..
    /// the update is ..  tree[root] = lpd[a'[i]]

    if(tree[root] == 1)
    {
        return ;
    }

    if(left==right)
    {
        a[left] = a[left] / LPD[a[left]];
        tree[root] = LPD[a[left]];
        return ;
    }

    lli mid  = (left + right ) / 2;
    update(start , end , 2*root ,  left , mid );
    update(start , end , 2*root + 1 , mid + 1 , right );

    tree[root] = maximum( tree[2*root] , tree[2*root + 1]);
}


int main()
{
    lli t, i, m, q , s , e;
    cin>>t;
    precalc();

    while(t--)
    {

        cin>>n>>m;
        //cout<<"n is "<<n<<endl;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        while(m--)
        {
            cin>>q>>s>>e;
            s--; e--;

            if(q==1)
            {
                int mx = 0;
                for(i=s;i<=e;i++)
                {
                    mx = maximum(mx , LPD[a[i]]);
                }
                cout<<mx<<" ";

            }
            else
            {
                for(i=s;i<=e;i++)
                {
                    a[i]=a[i]/LPD[a[i]];
                }

                cout<<"updated array ";
                for(i=0;i<n;i++)
                    cout<<a[i]<<" ";

                cout<<endl;
            }
        }

        cout<<endl;
    }
}
