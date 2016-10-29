#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class disjoint_set
{
    int n;
    vi a;

    public:
    disjoint_set(int N)
    {
        n = N;
        a=vi(n,-1);
    }

    int find_set(int x)
    {
        if(a[x]<0)
            return x;

        a[x]=find_set(a[x]);
        return a[x];
    }

    void union_set(int x1 , int x2)
    {
        int root1=find_set(x1) , root2= find_set(x2);
        if(root1==root2)
            return;

        if(abs(a[root1]) < abs(a[root2]))
        {
            a[root2]+=a[root1];
            a[root1]=root2;
        }
        else
        {
            a[root1]+=a[root2];
            a[root2]=root1;
        }
    }


};
int main1()
{
    disjoint_set s(10);

    char c;int x , x1;
    while(true)
    {
        cin>>c>>x;
        if(c=='f')
            cout<<"     "<<s.find_set(x)<<endl;

        else
        {
            cin>>x1;
            s.union_set(x,x1);
        }
    }
}

