#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

const int inf = 99999999 ;
/// just a regular priority que based on the number's values
int n;
vi a; /// assume 1 indexing
void print();
void swap_pos(int i1 , int i2)
{
    int t= a[i1];
    a[i1]= a[i2];
    a[i2]= t;
}
void bubble_up(int i)
{
    if(i==1)
        return;
    //cout<<"at node "<<i<<" : ";
    cout<<" now heap is "<<endl;print();
    //cout<<a[i]<<endl;
    if(a[i] < a[i/2])
    {
        swap_pos(i,i/2);
        bubble_up(i/2);
    }
}
int val(int pos)
{
    if(pos<=n)return a[pos];

    return inf;
}

void bubble_down(int i) /// should really be called sink_down
{
    int minchild = val(2*i) < val(2*i + 1) ? 2*i : 2*i + 1;
    if(a[i] > val(minchild))
    {
        swap_pos(i, minchild);
        bubble_down(minchild);
    }
}

void heap_insert(int x)
{
    n++;
    a.push_back(x);
    bubble_up(n);
}

int peep_min()
{
    return a[1];
}

int remove_min()
{
    int x = a[1];
    a[1]=a[n];
    n--;
    bubble_down(1);
    return x;
}

int hob (int num) ///higest order bit
{
    if (!num)
    	return 0;

    int ret = 1;

    while (num >>= 1)
    	ret <<= 1;

    return ret;
}

void build_heap()
{
    int i;
    for(i=hob(n);i>=1;i--)
    {
        bubble_down(i);
    }
}

///___________________________

void print()
{
    int i;
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
}
int main()
{
    int arr[]= {inf , 5 , 1 , 3 , 1 , 2};
    a= vi(arr, arr+6); n = 5 ;
    print();

    build_heap();
    print();

    heap_insert(0);
    print();

    heap_insert(-2);
    print();

    remove_min();
    print();

    remove_min();
    print();

    heap_insert(3);
    print();

    remove_min();
    print();

    remove_min();
    print();

    remove_min();
    print();

    remove_min();
    print();
}
