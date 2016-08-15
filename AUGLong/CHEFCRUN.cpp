//Nilanjana Lodh
#include <bits/stdc++.h>
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
lli n;
vli r,xtras;

lli minimize()
{
    int l= xtras.size();
    lli frilleft[l], frillright[l];
    // you get an array like [-2, 4 , -3 , 5 , -1]
    // see how much you can cover from both the sides
    lli curr=xtras[0];
    frilleft[0]=minimum(0,xtras[0]);
    int i;
    for(i=1;i<l;i++)
    {
        curr += xtras[i];

        frilleft[i]=minimum(frilleft[i-1], curr);
    }

    curr=xtras[l-1];
    frillright[l-1]=minimum(0,xtras[l-1]);

    for(i=l-2;i>=0;i--)
    {
        curr +=xtras[i];

        frillright[i]=minimum(frillright[i+1], curr);
    }

    lli ans=0,tmp;
    for(i=0;i<l-1;i++)
    {
        tmp=frilleft[i]+frillright[i+1];
        if(tmp<ans)
            ans=tmp;
    }

    if(frilleft[l-1]<ans)ans=frilleft[l-1];

    if(frillright[0]<ans) ans= frillright[0];

    return ans;
    

}

int main()
{
    lli t,i,x,y;
    cin>>t;
    lli minfrills, mainpath,opt1,opt2,ans;
    while(t--)
    {
        cin>>n;
        r=vli(n);

        for(i=0;i<n;i++)
            cin>>r[i];
    
        cin>>x>>y;
        x--; y--;//doing this because 0 indexing

        //option 1 
        //  0 1 2 3 4 
        //  1 3
        //  take the path 1->2->3
        //  so add r[1] + r[2]
       
        mainpath=0;
        for(i=x;i<y;i++)
            mainpath+=r[i];

        //now comes the frills  part.

        //xtras=vli(0);
        xtras.clear();
        for(i=y;i<n;i++)
            xtras.push_back(r[i]);

        for(i=0;i<x;i++)
            xtras.push_back(r[i]);

        minfrills= minimize(); 
        ///it will process this array xtras
        
        opt1= (2*minfrills) + mainpath;


        // option 2
        // u take the the other path, i.e
        // for 0 1 2 3 4
        // 1 3
        // you take the path 3->4->0->1
        //
        // and the frilly part is 1-2-3
    

        mainpath=0;
        for(i=y;i<n;i++)
            mainpath+=r[i];
        
        for(i=0;i<x;i++)
            mainpath+=r[i];

        //xtras=vli(0);
        xtras.clear();
        for(i=x;i<y;i++)
            xtras.push_back(r[i]);

        minfrills = minimize();
        opt2=(2*minfrills) + mainpath;

        //______now compare both__________
    
        ans=minimum(opt1,opt2);

        cout<<ans<<endl;
    }
}
