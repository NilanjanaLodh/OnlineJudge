//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;




bool isprime[1000006];
int LPD[1000006];


void precalc(int n=1000000)
{
    memset(isprime, true , sizeof(bool)*(n+1));

    int p,i;
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

int a[1000006];
int n; /// number of elements
int tree[4000909];

void build(int root=1, int start = 0, int end = (n-1))
{
    if(start==end)
    {
        tree[root]= LPD[a[start]];
    }

    else
    {
        int mid = (start + end )/2 ;
        build(2*root , start , mid);
        build(2*root + 1 , mid+1 , end);

        tree[root]= max(tree[2*root] , tree[2*root + 1]);
    }

    //cout<<"built range ["<<start<<" , "<<end<<"]  :"<<tree[root]<<endl;
}

void updateRange(int l , int r, int root=1, int s=0, int e= (n-1))
{
    if(s>e or e<l or r<s)
        return;

    if(tree[root]==1)
        return ;

    if(s==e)
    {
        a[s]= a[s]/LPD[a[s]] ;
        tree[root] = LPD[a[s]];
    }
    else
    {
        int mid= (s+e)/2;
        updateRange(l,r,2*root, s, mid);
        updateRange(l,r, 2*root + 1 , mid+1 , e);

        tree[root]=max(tree[2*root] , tree[2 * root  + 1]);
    }
}
int query(int l, int r, int root=1 , int s=0, int e=(n-1))
{
    if(e<l or r<s)
        return 0;

    if(l<=s and e<=r)
        return tree[root];

    int mid =(s + e)/2;
    return max(query(l,r,2*root, s, mid), query(l,r,2*root + 1, mid+1 , e));


}

int main()
{
    int t, i, m, q , l , r;
    scanf("%d", &t);
    precalc();

    while(t--)
    {

        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        build();
        while(m--)
        {
            scanf("%d%d%d",&q,&l,&r);
            l--; r--;

            if(q==1)
            {
                printf("%d ",query(l,r));
            }

            else
            {
                updateRange(l,r);
            }
        }

        printf("\n");
    }
}
