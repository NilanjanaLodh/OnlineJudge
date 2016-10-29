//Nilanjana Lodh
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<bool> vb;

const int inf= 1000000000;

void print(vector<vi> a)
{
    int n=a.size();
    int m=a[0].size();
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }

    cout<<"__________"<<endl;
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;

    vector<vi> a = vector<vi>(n+2 , vi(m+2 , -1)) ;
    vector<vi> b_upto = vector<vi>(n+2 , vi(m+2 , 0)) ;
    vector<vi> b_start = vector<vi>(n+2 , vi(m+2 , 0)) ;
    vector<vi> g_upto = vector<vi>(n+2 , vi(m+2 , 0)) ;
    vector<vi> g_start = vector<vi>(n+2 , vi(m+2 , 0)) ;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

//    /** initializations for base cases **/
//    for(j=0;j<=m+1;j++)
//        b_upto[0][j] = 0;
//    for(i=0;i<=n+1;i++)
//        b_upto[i][0] = 0;
//
//    for(j=0;j<=m+1;j++)
//        b_start[n+1][j] = 0;
//    for(i=0;i<=n+1;i++)
//        b_start[i][m+1] = 0;
//
//    for(j=0;j<=m+1;j++)
//        g_upto[n+1][j] = 0;
//    for(i=0;i<=n+1;i++)
//        g_upto[i][0] = 0;
//
//    for(j=0;j<=m+1;j++)
//        g_start[0][j] = 0;
//    for(i=0;i<=n+1;i++)
//        g_start[i][m+1] = 0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            b_upto[i][j]= max(b_upto[i-1][j] , b_upto[i][j-1]) + a[i][j];
        }
    }
    //print(b_upto);

    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            b_start[i][j]= max(b_start[i+1][j] , b_start[i][j+1]) + a[i][j];
        }
    }
    //print(b_start);

    for(i=n;i>=1;i--)
    {
        for(j=1;j<=m;j++)
        {
            g_upto[i][j]= max(g_upto[i][j-1] , g_upto[i+1][j]) + a[i][j];
        }
    }
    //print(g_upto);

    for(i=1;i<=n;i++)
    {
        /**

        -----*(1,m)
         ^   |
         |   |
         .-> |
             |
        **/
        for(j=m;j>=1;j--)
        {
            g_start[i][j]= max(g_start[i-1][j] , g_start[i][j+1]) + a[i][j];
        }
    }
    //print(g_start);

    int maxgain = 0;
    int  tmpgain1 , tmpgain2;
    for(i=2;i<n;i++)
    {
        for(j=2;j<m;j++)
        {

            tmpgain1 = g_upto[i][j-1] + g_start[i][j+1] + b_upto[i-1][j] + b_start[i+1][j] ;
            tmpgain2 = b_upto[i][j-1] + b_start[i][j+1] + g_upto[i+1][j] + g_start[i-1][j] ;
            //cout<<i<<" "<<j<<":- "<<endl;
            //cout<<" opt1 ("<<b_upto[i-1][j]<<","<<b_start[i+1][j]<<")    ,   ("<<g_upto[i][j-1]<<" , "<<g_start[i][j+1]<<") "<<endl;
            //cout<<" opt2 ("<<b_upto[i][j-1]<<","<<b_start[i][j+1]<<")    ,   ("<<g_upto[i+1][j]<<" , "<<g_start[i-1][j]<<") "<<endl;
            maxgain= max (maxgain , max(tmpgain1, tmpgain2));
        }
        //cout<<endl;
    }
    cout<<maxgain<<endl;
    return 0;
}
