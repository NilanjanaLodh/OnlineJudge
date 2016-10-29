//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

typedef pair<lli , int > data; //first - number , second - index
int n;
vli a;
vector<data> b;
vi new_index;
vb inplace;
int swaps;//store the no. of swaps
vector<pair<int,int> > swap_ind; //store the swapping indices
void cyclic_allocate(int start);
int main()
{
    cin>>n;

    int i; lli x;

    for(i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
        b.push_back(make_pair(x,i));
    }
    sort(b.begin(), b.end());

    new_index = vi(n);

    int old_index;
    for(i=0;i<n;i++)
    {
        old_index= b[i].second;
        new_index[old_index]=i;
    }

    inplace = vb(n, false);
    swaps = 0;
    for(i=0;i<n;i++)
    {
        if(!inplace[i])
            cyclic_allocate(i);
    }

    cout<<swaps<<endl;
    pair<int,int> p;
    for(i=0;i<swap_ind.size();i++)
    {
        p =swap_ind[i];
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}
void cyclic_allocate(int start)
{
    vb onstack(n,false);
    onstack[start]=true;inplace[start]=true;
    int next = new_index[start];

    while(!onstack[next])
    {
        swaps++;
        swap_ind.push_back(make_pair(start,next));

        onstack[next]=true;
        inplace[next]= true;

        next = new_index[next];
    }
}
