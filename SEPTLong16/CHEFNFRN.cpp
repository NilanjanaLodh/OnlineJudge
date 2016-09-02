//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

const lli inf= 9000000000000;
const lli mod= 1000000007;
vector<vb> adj;
vector<vi> neigh;
vi color;
int n;


bool color_graph(int start)
{
    int node,i,s;
    queue<int> q;
    color[start]=0;
    q.push(start);
    while(!q.empty())
    {
        s= q.front(); q.pop();

        for(i=0;i<neigh[s].size();i++)
        {
            node = neigh[s][i];
            if(color[node]==color[s])
                return false;

            if(color[node]==-1)
                q.push(node);
            color[node] = 1 - color[s] ;
        }
    }
    return true;
}

bool color_graph()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(color_graph(i) == false)
                return false;
        }
    }

    return true;
}

int main()
{

    int t,m,x,y,i,j;
    scanf("%d",&t);
    while(t--)
    {
      //  cout<<"____________"<<endl;
        scanf("%d%d",&n,&m);
      //  cout<<"n = "<<n<<endl<<"m = "<<m<<endl;
        adj = vector<vb>(n,vb(n,true));
        while(m--)
        {
            scanf("%d%d",&x,&y);x--;y--;
            adj[x][y]=adj[y][x]=false;
        }
        color = vi(n,-1);
        neigh = vector<vi>(n,vi(0));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((i!=j) && adj[i][j])
                    {
        //                cout<<i<<"  "<<j<<endl;
                        neigh[i].push_back(j);
                    }
            }
        }

        if(color_graph()==true)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
