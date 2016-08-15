//Nilanjana Lodh
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
const lli inf= 9000000000000;
const lli mod= 1000000007;
lli minimum(lli a, lli b)
{
    if(a<b)return a;
    return b;
}
lli maximum(lli a, lli b)
{
    if(a>b)return a;
    return b;
}
lli pow(lli a, lli b)
{
    if(b==0)
        return 1;
    lli ans = pow(a,b/2);
    if(b%2==1)ans= (ans*ans)%mod;
    return ans;
}

int main()
{
    int t,i,firstnode, next;
    lli n;
    cin>>t;
    vi cycle,onstack;
    int count;
    vli jump;
    while(t--)
    {
        stack<int> s;
        scanf("%lld",&n);

        jump= vli(n);
        count =0;
        cycle=vi(n,-1);
        onstack=vi(n,0);
        for(i=0;i<n;i++)
            scanf("%lld",&jump[i]);

        for(i=0;i<n;i++)
        {
            if(cycle[i]==-1)///untouched , stacking up( cycle detection starts)
            {
                s.push(i);onstack[i]=true;
                next=(i+jump[i]+1)%n;
                ///lets optimize : either youll find a new cycle,OR...
                //you ll run into a node whose status is already known
                while(!onstack[next])///there will be atleast 1 cyc
                {
                    //if the status of this node is already known then this a dead end
                    if(cycle[next]!=-1)
                        goto nocycle;
                    s.push(next); onstack[next]=true;
                    next=(next + jump[next]+ 1)%n;
                }
                ///at this point you have completed the cycle
                firstnode= next; //the first node of the cycle
                while(s.top()!=firstnode)
                {
                    cycle[s.top()]=true;
                    onstack[s.top()]=false;
                    s.pop();
                }
                /// we are now removing the first node 
                // and with this, we finish the cycle.
                cycle[s.top()]=true;
                onstack[s.top()]=false;
                s.pop();
                nocycle:
                while(!s.empty())
                {
                    cycle[s.top()]=false;
                    onstack[s.top()]=false;
                    s.pop();
                }/// this was the 'tail' part
            }
            if(cycle[i]==true)
                count++;
        }
       printf("%d\n",count);
    }
}
