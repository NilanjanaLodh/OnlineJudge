// Problem URL : http://www.spoj.com/problems/SQRBR/
/*
*	Nilanjana Lodh
*	Genre : DP
*	Difficulty :  Medium
* 	Misc : Should try to understand normal paranthesis printing before attempting this
*/

#include <iostream>
#include <vector>

using namespace std;
typedef long long int lli;

int n,k;
vector<bool> sequence;
vector< vector<lli> > DP;
int count(int index=1, int unclosed_so_far=0)// unclosed_so_far is the no. of brackets that need to be closed upto(including) in
{

    if(DP[index][unclosed_so_far]!=-1)
        return DP[index][unclosed_so_far];

    if(index==(2*n+1))//unclosed_so_far ==0
    {
        DP[index][unclosed_so_far]=(unclosed_so_far==0);
        return DP[index][unclosed_so_far];
    }

    else if(unclosed_so_far>(2*n-index+1))
        {
            DP[index][unclosed_so_far]=0;
            return DP[index][unclosed_so_far];
        }

    else if(sequence[index]==true)
    {
        DP[index][unclosed_so_far]= count(index+1,unclosed_so_far+1);
        return DP[index][unclosed_so_far];
    }

    else
    {
        ///empty spot


        int ans=0;
        if(unclosed_so_far>0)
        {
            //put a closing bracket

            int tmp=count(index+1,unclosed_so_far-1);


            ans += tmp;

        }

        if(unclosed_so_far<n)
        {

            int tmp= count(index+1,unclosed_so_far+1);

            ans +=  tmp;

        }

        DP[index][unclosed_so_far]= ans;
        return DP[index][unclosed_so_far];

    }

}
int main1()
{
    n=1;
        sequence=vector<bool>(2*n + 5 , false);

}
int main()
{
    int t,i,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sequence=vector<bool>(2*n + 5 , false);
        DP=vector< vector<lli> > (2*n + 5, vector<lli>(2*n +5 , -1));

        for(i=0;i<k;i++)
        {
            cin>>x;
            sequence[x]=true;
        }
        cout<<count(1,0)<<endl;
    }
}
