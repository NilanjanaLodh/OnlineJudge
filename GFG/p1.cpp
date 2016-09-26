//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef bitset<1010> bitvec;

const lli inf= 9000000000000;
const lli mod= 1000000007;

int n;
int rootnode;
vector<bool> root;
vector<bitvec>  adj;
vector<vi> alist;

void find_reachable(int start)
{
    int i,node;
    for(i=0;i<alist[start].size();i++)
    {
        node = alist[start][i];
        find_reachable(node);
        adj[start] |= adj[node];
    }
}

int query(int a, int b)
{
    if(adj[a][b])
        return a;

    if(adj[b][a])
        return b;

    return -2;
}

int main()
{
    int t,i;
    cin>>t;
    int x,y,q;
    while(t--)
    {
        cin>>n;
        root= vector<bool>(n,1);
        adj = vector<bitvec>(n);
        alist = vector<vi>(n,vi(0));
        for(i=1;i<n;i++)
        {
            cin>>x>>y;
            x--;y--;
            root[y]=false;
            adj[x][y]=true;
            alist[x].push_back(y);
        }
        for(i=0;i<n;i++)
        {
            if(root[i])
            {
                rootnode = i;
                break;
            }
        }
        find_reachable(rootnode);

        cin>>q;
        while(q--)
        {
            cin>>x>>y;
            x--; y--;
            cout<<(query(x,y)+1)<<" ";

        }
        cout<<endl;
    }
}


