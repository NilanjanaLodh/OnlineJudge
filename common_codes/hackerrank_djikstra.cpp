#include <iostream>
#include <vector>
#include <queue>
#include<limits>
#define INF 99999999999999999
#define for_all_neighbours(i,v) for(i=0;i<alist[v].size();i++)

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli,lli> Pair;

typedef Pair vertex;/// vertex is a Pair with index,cost pair
typedef vi edge;


edge make_edge(lli weight, lli u, lli v)
{
    edge e(3);
    e[0]=weight;
    e[1]=u;
    e[2]=v;

    return e;
}

class Graph
{
public:
    lli V, E, source;
    vector< vector<vertex> > alist;
    vector<lli> dist;///djikstra distance
    vector<lli> parent;///djikstra parent
    Graph(lli v, lli e):V(v), E(e), alist(V, vector<vertex>(0) ), dist(V, INF), parent(V, -1)
    {}

    void addEdge(lli weight, lli u, lli v)///undirected graph
    {
        alist[u].push_back(make_pair(v, weight));
        alist[v].push_back(make_pair(u, weight));
    }
    void input()
    {
        lli i,u,v, weight;
        for(i=0;i<E;i++)
        {
            cin>>u>>v>>weight;
            u--; v--;
            addEdge(weight,u,v);
        }
        cin>>source;
        source--;

    }
    void dijktstra()
    {
        ///priority que of vertices,
        ///but the vertex pairs are inverted because we need to sort based on distance from the source
        priority_queue<vertex, vector<vertex> , greater<vertex> > pq; ///minheap

        ///assume dist[.. ] to be all filled with INF

        dist[source]=0;
        pq.push(make_pair(dist[source] ,source));


        /***
         Each element of the priority queue is a pair of the form (distance from source, index of the vertex)
        **/

        lli v,d,u_index,u_cost,i;
        vertex u;
        while(!pq.empty())
        {
                vertex alarm_ring_vertex= pq.top();
                pq.pop();

                v=alarm_ring_vertex.second; /// which vertex has been "reached" ?
                d=alarm_ring_vertex.first;  ///how far is it from the source?

                for_all_neighbours(i,v)
                {
                    u=alist[v][i];
                    u_index=u.first;
                    u_cost=u.second;

                    if(dist[u_index]>(d + u_cost))
                    {
                        parent[u_index]=v;
                        dist[u_index]=d+u_cost;///update distance
                        pq.push(make_pair(dist[u_index],u_index));
                    }
                }
        }
    }

    void print()
    {
        lli i;
        for(i=0;i<V;i++)
        {
            if(i!=source)
            {
                if(dist[i]==INF)
                    cout<<"-1 ";
                else
                    cout<<dist[i]<<" ";
            }

        }

        cout<<endl;
    }

};
int main()
{
    int t;
    cin>>t;
    lli v, e;

    while(t--)
    {
        cin>>v>>e;
        Graph g(v,e);
        g.input();
        g.dijktstra();
        g.print();
    }
}
