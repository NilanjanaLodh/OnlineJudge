#include <iostream>
#include <vector>
#include <queue>
#define INF 999999


using namespace std;

typedef vector<int> vi;

class Graph
{
public:
    int V, E;

    vector< vi > alist;
    vi BFS_parent;
    vi BFS_dist;
    int root;

    Graph(int v, int e): V(v), E(e), alist(v, vi(0)),BFS_dist(v,-1), BFS_parent(v,-1)
    {}

    void addEdge(int u, int v)
    {
        alist[u].push_back(v);
        alist[v].push_back(u);
    }

    void input()
    {
        int i;
        int u,v;

        for(i=0;i<E;i++)
        {
            cin>>u>>v;
            u--; v--;
            addEdge(u,v);

        }

        cin>>root;
        root--;
    }

    void BFS()
    {
        queue<int> q;
        q.push(root);
        BFS_dist[root]=0;
        int i,v,f;

        while(!q.empty())
        {
            f=q.front();
            q.pop();
            for(i=0;i<alist[f].size();i++)
            {
                v=alist[f][i];
                if(BFS_parent[v]==-1)
                {
                    q.push(v);
                    BFS_parent[v]=f;
                    BFS_dist[v]=BFS_dist[f]+1;
                }
            }
        }
    }

    void print()
    {
        int i;
        for(i=0;i<V;i++)
        {
            if(i!=root)
                cout<<BFS_dist[i]<<" ";
        }

        cout<<endl;
    }

};

int main()
{

    int t, v, e;
    cin>>t;
    while(t--)
    {
        cin>>v>>e;
        Graph g(v,e);
        g.input();
        g.BFS();
        g.print();
    }
}

