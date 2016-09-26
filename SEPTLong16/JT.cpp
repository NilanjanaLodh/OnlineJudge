//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef pair<int , lli > pr;
typedef vector<pr> vpr;

const lli inf= 9000000000000000000;

lli minimum(lli a, lli b)
{
    if(a<b)return a;
    return b;
}

vli mincost_dp;
vi level;
vi parent;
vector<vpr> tickets;
int n;

lli tree[1000000]; /// stores the segtree
int l; /// the largest level for which I'm constructing the segment tree
int node[100100]; /// the node number for each node in the path
lli a[100100]; /// the base table beneath the segtree


void allocate_level(int v)
{
    if(level[v]!=-1)
        return ;//already allocated

    if(v==0)
    {
        level[v]=0;
        return;
    }

    allocate_level(parent[v]);
    level[v]= level[parent[v]] + 1;
}

void build(int root=1 , int s=0 , int e=l)
{
    if(s==e)
    {
        tree[root] = a[s] ;
        return;
    }

    else
    {
        int mid = (s+e)/2;

        build(2*root , s, mid);
        build(2*root + 1 , mid+1 , e);

        tree[root] = minimum(tree[2*root] , tree[2*root + 1]);
    }
}

lli query(int left , int right , int root=1 , int s=0 , int e=l)
{
    if(e<left or right<s)
        return inf;

    if(left<=s && e<=right)
        return tree[root];

    else
    {
        int mid = (s+e)/2;

        return minimum(query(left, right , 2*root , s , mid) , query(left, right , 2*root + 1 , mid + 1 , e));
    }
}

void update(int ind , int val ,int root=1,  int s=0, int e=l)
{
    if(ind<s or ind>e or e<s)
        return ;

    if(s==e)
    {
        a[ind]=val;
        tree[root] = val;
    }

    else
    {
        int mid= (s+e)/2;
        if(ind<=mid)
            update(ind,val,2*root , s, mid);

        else
            update(ind , val , 2*root + 1 , mid +1 , e);

        tree[root] = minimum(tree[2*root] , tree[2*root + 1]);
    }
}

lli mincost(int v)
{
    if(mincost_dp[v]!=-1)
        return mincost_dp[v];

    int tsize = tickets[v].size() ;
    l = level[v];

    if(tsize==0)
    {
        mincost_dp[v] = inf ;
        return inf ;
    }

    int i,k,t;
    lli tnode = inf ;
    lli w;

    for(i=0 ;i<tsize; i++)
    {
        k = tickets[v][i].first;
        w = tickets[v][i].second ;

        if(k>=l)
        tnode = minimum(tnode, w);

    }

    if(tnode<inf)
    {
        mincost_dp[v] = tnode ;
        return tnode;
    }

    int curr = v;

    for(i=l ; i>=0 ; i--)
    {
        node[i]= curr;

        if(mincost_dp[curr] != -1)
        {
            a[i] = mincost_dp[curr];
        }

        else
        {
            a[i] = inf;
        }

        curr = parent[curr];
    }

    build();
    lli tc;
    for(i=0;i<=l;i++)
    {
        curr= node[i];

        if(mincost_dp[curr]==-1)
        {
            tnode = inf ;
            tsize = tickets[curr].size();
            for(t=0;t<tsize;t++)
            {
                k = tickets[curr][t].first ;
                w = tickets[curr][t].second ;

                if(k>=i)
                {
                    tnode = minimum(tnode , w) ;
                }
                else
                {
                    lli x = query(i-k , i);

                    if(x!=inf)
                    {
                        tc = w + query(i-k , i);
                        tnode= minimum(tnode , tc);
                    }
                }

            }

            mincost_dp[curr] = tnode ;
            update(i, tnode);
        }
    }

    return mincost_dp[v];
}

int main()
{
    int m, i,q;
    cin>>n>>m;
    int u,v,k;
    lli w;
    mincost_dp=vli(n,-1);
    mincost_dp[0] = 0;

    level= vi(n,-1);
    parent= vi(n,0);
    tickets = vector<vpr>(n,vpr(0));

    for(i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        u--; v-- ;
        parent[u] = v;
    }

    //cout<<"levels allocated\n";
    for(i=0;i<n;i++)
        {
            allocate_level(i);
            //cout<<i<<" : "<<level[i]<<endl;
        }
    for(i=0;i<m;i++)
    {
        scanf("%d%d%lld",&v, &k, &w);
        v--;
        tickets[v].push_back(make_pair(k,w));

    }

    cin>>q;
    while(q--)
    {
        scanf("%d", &v);
        v--;
        cout<<mincost(v)<<endl;
    }
}

