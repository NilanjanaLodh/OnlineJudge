///#include <bits/stdc++.h>/// I'm  not doing this because of slow compilation
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>///for memset
#define INF 99999999
using namespace std;

typedef vector<int> vi;

class Graph
{
    public:
        int V;
        vector< vi > alist;

        vi dist;
        vi BFS_parent;

        vector<bool> DFS_visited;
        Graph(int v):V(v) , alist(v, vi(0)) , BFS_parent(v, -1) , dist(v, INF), DFS_visited(v,false)
        {}

        void addEdge(int v, int w)
        {
            alist[v].push_back(w);
        }
        void input()
        {
            int edges;
            //cout<<"Edges :";
            cin>>edges;
            int i;
            int u, v;
            for(i=0;i<edges;i++)
            {
                cin>>u>>v;
               // u-='A'; v-='A';///this line should be uncommented iff nodes are characters
                /// u--; v--; /// this line should be uncommented if you want to input in 1 - index mode
                addEdge(u,v);
                addEdge(v,u); ///this line should be commented to make it a directed graph
            }
        }

        void BFS(int root=0)
        {
            queue<int> q;
            q.push(root);
            dist[root]=0;
            BFS_parent[root]=-1;

            int front,i,v;
            while(!q.empty())
            {
                    front=q.front();
                    q.pop();

                    cout<<front<<"\t";

                    for(i=0;i<alist[front].size();i++)//for all neighbours
                    {
                        v=alist[front][i];
                        if(dist[ v ] ==INF )
                        {
                            /// this node has not been considered yet
                            q.push(v);
                            BFS_parent[v]=front;
                            dist[v]=dist[front] + 1;
                        }
                    }
            }



        }

        void trace_back(int v, int root=0)
        {

            if(v!=root)
            {
                trace_back(BFS_parent[v],root);
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
                v=alist[source][i];
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
                v=alist[source][i];
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





};

int main()
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
