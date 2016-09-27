//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef pair<lli, lli > Pair;
const lli inf= 9000000000000;
const lli mod= 1000000007;

int n;
vector< vector<Pair> >tickets;//first -> k , second -> w
vector< vi >children ;
vli cost;

void computeCost(int node , stack<Pair> st , map<lli , lli> mp)
{
    ///Pair : (cost from that node , level of that node) -->
    ///       (cost , level)
    ///mp[level]= cost ---> for easy searching

    //cout<<"At node "<<node<<endl;
    if(node==0)
    {
        st.push(make_pair(0,0));
        mp[0]=0;
        cost[0] =0;
    }
    else
    {
        int i;
        int currentlevel = st.top().second + 1;
        lli tmpcost , mincost= inf;
        for(i=0;i<tickets[node].size();i++)
        {
            Pair t = tickets[node][i];
            lli t_k = t.first;
            lli t_w = t.second;

            if(t_k>=currentlevel)
                tmpcost = t_w ;

            else
            {
                tmpcost = t_w + (mp.lower_bound(currentlevel - t_k)->second) ;
            }

            if(tmpcost<mincost) mincost = tmpcost ;

        }

        lli top_cost = st.top().first ;
        lli top_level = st.top().second ;

        while(top_cost >= mincost)
        {
            st.pop();
            mp.erase(mp.find(top_level));

            top_cost = st.top().first ;
            top_level = st.top().second ;
        }

        st.push(make_pair(mincost,currentlevel));
        mp[currentlevel] = mincost ;
        cost[node]=mincost;
    }

    int i,v;
    for(i=0;i<children[node].size();i++)
    {
        v = children[node][i];
        computeCost(v, st , mp);
    }
}

int main()
{
    int m, x, y;
    scanf("%d%d",&n,&m);
    children = vector<vi>(n,vi(0));
    tickets = vector< vector<Pair> >(n, vector<Pair>(0));
    cost = vli(n);

    int e=n-1;
    while(e--)
    {
        scanf("%d%d",&x, &y);
        x--;y--;
        children[y].push_back(x);
    }
    int v, k , w;
    while(m--)
    {
        scanf("%d%d%d",&v, &k, &w);
        v--;
        tickets[v].push_back(make_pair(k,w));
    }
    stack<Pair> s ;map<lli, lli> mp;

    computeCost(0,s,mp);

    int q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d",&x);
        x--;
        printf("%lld\n",cost[x]);

    }
    return 0;
}
