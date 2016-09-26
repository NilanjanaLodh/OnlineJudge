//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef pair<int , lli > pr;
typedef vector<pr> vpr;

const lli inf= 999999999999999999;

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


lli seg[1000000]; /// stores the segtree
int l; /// the largest level for which I'm constructing the segment tree
int node[100100]; /// the node number for each node in the path
lli a[100100]; /// the base table beneath the segtree

void build(int root = 1, int left=0, int right= l)
{
    if(left==right)
    {
        seg[root] = a[left];
        return;
    }
    int mid = (left + right)/2 ;
    build(2*root , left , mid);
    build(2*root + 1 , mid + 1, right);

    seg[root] = minimum(seg[2*root] , seg[2*root + 1]);
}

void update(int index, int newval, int root=1, int left=0 , int right= l)
{
    /// after updating the segtree, also update a[index] and mindis
    if(index<left || index>right)
        return;

    if(left==right)
        seg[root] = newval;

    else
    {
        int mid=(left + right)/2;
        update(index, newval , 2*root , left ,mid);
        update(index, newval , 2*root+1 , mid+1 , right);
        seg[root]=minimum(seg[root] , newval);
    }

}

lli query(int start , int end , int root=1 , int left=0 , int right= l)
{
    /// basically this is asking the question.. what is the contribution of node 'root'(with range [left,right] ) towards the range start to end
    /// so we need to compare the node ranges (left and right) with the query ranges (start and end)


    if(right<start || end<left)
    {
        /**
                                        start-----------------------end
                    left------right              OR                      left------right
        **/
        return inf;
    }

    else if(start<=left && end>=right)
    {
        /**
            start-----------------------end
                    left------right
        **/
        return seg[root];
    }
    else
    {
        int mid = (left + right)/2;
        return minimum(query(start, end, (root<<1 ),left , mid) , query(start, end, ( (root<<1) | 1 ),  mid+1  , right));
    }
}

lli mincost(int v)
{
    if(mincost_dp[v]!=-1)
    return mincost_dp[v];

    if(v==0)
    {
        mincost_dp[v] = 0;
        return 0;
    }

    int t,i , tsz, curr , k;
    lli cost , tnodemin ,tc;
    bool direct=false;

    tsz = tickets[v].size();
    if(tsz==0)
    {
        mincost_dp[v]= inf ;
        return inf;
    }

    l = level[v];

    tnodemin = inf;
    for(t=0;t<tsz;t++)
    {
        k = tickets[v][t].first;
        if(k>=l)
        {
            direct = true;
            cost = tickets[v][t].second;
            tnodemin = minimum(tnodemin , cost);
        }
    }
    if(direct)
    {
        //cout<<"direct"<<endl;
        mincost_dp[v] = tnodemin;
        return tnodemin;
    }

    curr = v;
    for(i=l;i>=0;i--)
    {
        node[i]= curr;

        if(mincost_dp[curr]==-1)
        {
            a[i] = inf ;
        }
        else
        {
            a[i] = mincost_dp[curr];
        }
        curr = parent[curr];
    }

//    for(i=0;i<=l;i++)
//    {
//        cout<<node[i]<<" ";
//    }
//    cout<<endl;
//
//     for(i=0;i<=l;i++)
//    {
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;

    //cout<<"creating path for node "<<v<<endl;
    build();
    for(i=0;i<=l ;i++)
    {
        curr = node[i];
        //cout<<"level "<<i<<" ...\n";
        if(mincost_dp[curr]!=-1)
        {
            /// already done
            //cout<<"     already done\n";
            continue;
        }
        else
        {
            tnodemin = inf;
            tsz = tickets[curr].size();
            for(t=0;t<tsz;t++)
            {
                k = tickets[curr][t].first;
                cost = tickets[curr][t].second;

                if(k>=i)
                    tc = cost;

                else
                tc = cost + query(i-k , i-1);

                tnodemin = minimum(tnodemin , tc);
            }
            mincost_dp[curr] = tnodemin;
            if(tnodemin<inf)
            {
                a[i] = tnodemin;
                update(i, tnodemin);
            }
        }

    }
    return mincost_dp[v];


}
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
