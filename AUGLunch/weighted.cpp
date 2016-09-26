#include <bits/stdc++.h>/// I'm  not doing this because of slow compilation
//
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <string.h>///for memset


//#include "/home/nilanjana/Desktop/code/practice/data_structures/Heap.cpp"
//#include "/home/nilanjana/Desktop/code/practice/data_structures/Disjoint_set.cpp"
#define INF 99999999

#define vertex_name first
#define edge_weight second

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> vertex;
typedef vector<vertex> vertexlist;

typedef vector<int> edge;
pair<int,int> reverse(const pair<int,int> &p)
{
    pair<int,int> q=make_pair(p.second,p.first);

    return q;
}

edge make_edge(int weight, int u, int v)
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
        int V;
        vector< vertexlist > alist;


        vi BFS_dist;///BFS distance
        vi dist;///dijkstra distance
        vi parent;///dijkstra parent
        vi BFS_parent;


        vector <vertexlist > MST;///minimum spanning tree

        vector<bool> DFS_visited;


        Graph(int v):
            V(v) ,
            alist(v, vertexlist(0)) ,
            BFS_parent(v, -1) ,
            BFS_dist(v, INF),
            DFS_visited(v,false) ,
            dist(v, INF) ,
            parent(v, -1) ,
            MST(v, vertexlist(0))
        {}

        void addEdge(int v, int w, int weight)
        {
            alist[v].push_back(make_pair(w,weight));
        }

        void addEdgeMST(int v, int w, int weight)
        {
            MST[v].push_back(make_pair(w,weight));
            MST[w].push_back(make_pair(v,weight));
        }
        void input()
        {
            int edges;
            //cout<<"Edges :";
            cin>>edges;
            int i;
            int u, v,weight;
            for(i=0;i<edges;i++)
            {
                cin>>u>>v>>weight;
               // u-='A'; v-='A';///this line should be uncommented iff nodes are characters
                /// u--; v--; /// this line should be uncommented if you want to input in 1 - index mode
                addEdge(u,v,weight);
                addEdge(v,u,weight); ///this line should be commented to make it a directed graph
            }
        }

        void BFS(int root=0)
        {
            queue<int> q;
            q.push(root);
            BFS_dist[root]=0;
            BFS_parent[root]=-1;

            int front,i,v;
            while(!q.empty())
            {
                    front=q.front();
                    q.pop();

                    cout<<front<<"\t";

                    for(i=0;i<alist[front].size();i++)//for all neighbours
                    {
                        v=(alist[front][i]).vertex_name;
                        if(BFS_dist[ v ] ==INF )
                        {
                            /// this node has not been considered yet
                            q.push(v);
                            BFS_parent[v]=front;
                            BFS_dist[v]=BFS_dist[front] + 1;
                        }
                    }
            }

        }

        void trace_back(int v, int root=0)
        {

            if(v!=root)
            {
                trace_back(parent[v],root);
                cout<<"<-- ";
            }
            cout<<" "<<v<<" ";

        }

        void DFS_explore(int source, bool print=true)
        {
            int i;
            if(print)
            {
                cout<<" visiting ";///
                cout<<source<<endl;
            }
            DFS_visited[source]=true;
            if(print )cout<<" outgoing "<<endl;///

            int v;
            for(i=0;i<alist[source].size();i++)
            {
                v=alist[source][i].vertex_name;
                if(!DFS_visited[v])DFS_explore(v,print);
            }

            if(print)cout<<" return to "<<source<<endl;///
        }
        void DFS()
        {
            int i;
            DFS_visited= vector<bool>(V,false);
            for(i=0;i<V;i++)
            {
                if(!DFS_visited[i])
                {
                    DFS_explore(i);
                }
            }
        }

        bool detect_cycle()
        {
            /// beware, this works only on directed graphs
            bool onstack[V];
            memset(onstack,false, sizeof(bool)*V);
            DFS_visited=vector<bool>(V,false);
            int u;
            for(u=0;u<V;u++)
            {
                if(!DFS_visited[u])
                {
                    if(check_cycle_explore(u,onstack)==true)
                    {
                        cout<<"Cycle found "<<endl;
                        return true;
                    }
                }
            }

            cout<<"Acyclic graph"<<endl;
            return false;

        }

        bool check_cycle_explore(int source, bool onstack[])
        {
            ///directed graphs only
            ///this function returns whether there are any cycles from source
            int i;
           // cout<<source<<endl;
            DFS_visited[source]=true;/// this is for the sake of normal DFS

            onstack[source]=true;
            //cout<<source<<" onstck"<<endl;
            int v;
            for(i=0;i<alist[source].size();i++)
            {
                v=alist[source][i].vertex_name;
                if(onstack[v])
                {
                    cout<<"Backedge found"<<endl;
                    ///this means, we have got a back edge
                    return true;
                }
                if(!DFS_visited[v])
                {
                    if(check_cycle_explore(v,onstack)) return true;
                }
            }

            onstack[source]=false;

            return false;
            //cout<<" return to "<<source<<endl;///
        }


        int count_islands()
        {
            ///only for undirected graphs
            int i;
            DFS_visited= vector<bool>(V,false);
            int islands=0;
            for(i=0;i<V;i++)
            {
                if(!DFS_visited[i])
                {
                    islands++;
                    DFS_explore(i,false);
                }
            }
            return islands;
        }
        void dijkstra(int source =0)
        {

            priority_queue< vertex, vector<vertex> , greater<vertex> > pq;/// this will make a min heap
            ///but this one is going to be in reverse
            ///i.e <weight, vertex_index> instead of the usual <vertex_index, weight>
            ///this is because greater<pair<>> treats the first component as the key, and the second one as the value


            dist=vi(V, INF);

            dist[source]=0;
            pq.push(make_pair(dist[source],source));
            int v,d,i,u;

            while(!pq.empty())
            {
                vertex next=pq.top();//key, value --> dist, name
                pq.pop();
                v=next.second;
                cout<<"reached vertex "<<v<<endl;
                for(i=0;i<alist[v].size();i++)
                {
                    u=alist[v][i].vertex_name; /// the vertex index
                    d=alist[v][i].edge_weight;
                    cout<<"considering vertex "<<u<<endl;
                    if((dist[v]+d)<dist[u])
                    {

                        dist[u]=dist[v]+d;
                        parent[u]=v;
                        cout<<"updated "<<u<<" to "<<dist[u]<<endl;
                        pq.push(make_pair(dist[u],u));
                    }
                }

            }


            // Print shortest distances stored in dist[]
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < V; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
        }

        int prims()
        {
            priority_queue< edge , vector<edge> ,greater<edge> > pq;
            MST=vector<vertexlist> (V,vertexlist(0));

            vector<bool> green(V,false);///green means that vertex has been included in the MST

            green[0]=true;int count=1;
            int u,i, weight;
            int cost=0;

            for(i=0;i<alist[0].size();i++)
            {
                u=alist[0][i].vertex_name;
                weight=alist[0][i].edge_weight;

                pq.push(make_edge(weight,0,u));///this is like setting the boundary
            }
            edge e;
            int v1,v2;
            while(count<V)
            {
                e=pq.top();/// min cost edge
                pq.pop();


                weight=e[0];
                v1=e[1]; ///this belongs to S [green area]
                v2=e[2];/// this belongs to V-S {grey area}, new vertex

                if(green[v2]) ///this edge can't be included.. it will violate tree property
                    continue;

                cout<<"added edge "<<v1<<"--"<<v2<<" to MST "<<endl;

                ///now its time to include the edge in the mst
                addEdgeMST(v1,v2,weight);

                green[v2]=true;
                count++;
                cost+=weight;

                ///now expand frontiers .. include all those edges which form a bridge betwen grey and green area
                for(i=0;i<alist[v2].size();i++)
                {
                    u=alist[v2][i].first;
                    weight=alist[v2][i].second;
                    if(!green[u])
                    {
                        ///bridge edge found.. add it!
                        e=make_edge(weight,v2,u);
                        cout<<"     boundary edge "<<v2<<"--"<<u<<endl;
                        pq.push(e); ///push this new edge into the heap.. for retrieval
                    }
                }


            }
            return cost;

        }

        int kruskall()
        {

            ///phew.. using 2 fancy data structures together!
            ///priority que to always pick the minimum.. though u could do this with sorting as well... infact that would be better.
            /// will do it some day

            ///disjoint set data structure for the forests that ar growing


            priority_queue< edge , vector<edge> ,greater<edge> > pq;
            MST=vector<vertexlist> (V,vertexlist(0));

            Disjoint_set S(V);
            int i,u,v,weight;

            int cost=0;

            edge e;
            for(u=0;u<V;u++)
            {

                for(i=0;i<alist[u].size();i++)
                {
                    v=alist[u][i].first;
                    weight=alist[u][i].second;

                    e=make_edge(weight,u,v);
                    pq.push(e);
                }
            }///prepping !

            while(S.components>1)
            {
                e=pq.top();
                pq.pop();

                weight=e[0];
                u=e[1];
                v=e[2];

                if(S.find_set(u)!=S.find_set(v))
                {
                    ///disjoint
                    S.merge(u,v);
                    addEdgeMST(u,v,weight);
                    cost+=weight;
                }

            }

            return cost;




        }






};


int test()
{
    ///this function basically proves that the first component is checked for > (operator overloading)
    vector<int> v1(3,0); v1[0]=10; v1[1]=12; v1[2]=5;
    vector<int> v2(3,1); v2[0]=50;  v2[1]=23; v2[3]=1;

    if(v1>v2)
    {
        cout<<"v1"<<endl;
    }
    else
        cout<<"v2"<<endl;

}
int main_nonweighted()
{
    /**

    sample
    6 7

    0 1
    0 2
    1 2
    2 5
    3 2
    3 4
    4 5

    1___2______5
    |  /|      |
    | / |      |
    |/  |      |
    0   3______4

    **/
    cout<<"G=(V,E)"<<endl;
    int v;
    cin>>v;
    Graph *g= new Graph(v);
    g->input();
    g->BFS();
    cout<<endl;

    cout<<" traceback ";
    cin>>v;
    g->trace_back(v);
    cout<<endl;
    //g->DFS();


    cout<<(g->count_islands())<<" islands in the graph "<<endl;


    //g->detect_cycle();


}
int main()
{
    // create the graph given in above fugure

    Graph g(9);
    //  making above shown graph
//    g.addEdge(0, 1, 4);
//    g.addEdge(0, 7, 8);
//    g.addEdge(1, 2, 8);
//    g.addEdge(1, 7, 11);
//    g.addEdge(2, 3, 7);
//    g.addEdge(2, 8, 2);
//    g.addEdge(2, 5, 4);
//    g.addEdge(3, 4, 9);
//    g.addEdge(3, 5, 14);
//    g.addEdge(4, 5, 10);
//    g.addEdge(5, 6, 2);
//    g.addEdge(6, 7, 1);
//    g.addEdge(6, 8, 6);
//    g.addEdge(7, 8, 7);
    g.input();
    int i;


    g.dijkstra(0);


    for(i=0;i<g.V;i++)
    {
        g.trace_back(i);
        cout<<endl;
    }


    cout<<"Prim"<<endl<<g.prims()<<endl;
    int j;
    for(i=0;i<g.V;i++)
    {
        cout<<i<<" : ";
        for(j=0;j<g.MST[i].size();j++)
        {
            cout<<g.MST[i][j].first<<" ";
        }
        cout<<endl;
    }



     cout<<"Kruskall"<<endl<<g.kruskall()<<endl;

    for(i=0;i<g.V;i++)
    {
        cout<<i<<" : ";
        for(j=0;j<g.MST[i].size();j++)
        {
            cout<<g.MST[i][j].first<<" ";
        }
        cout<<endl;
    }
    return 0;
}
