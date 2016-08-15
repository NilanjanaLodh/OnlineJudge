//Nilanjana Lodh
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;
const lli inf= 999999999999999999;
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
lli ub,lb; // this is the lb n ub so far // initially lb=0 n ub= inf
lli tub,tlb;
bool ubflag, lbflag, impossible;
void solvelessthan(lli lhsn, lli lhst, lli rhsn, lli rhst);

void print(lli x, lli y)
{
    cout<<x<<" ";
    if(y==inf)
    {
        cout<<"Inf"<<endl;
    }

    else
        cout<<y<<endl;
}
int main()
{
    int t,i,n,q;
    cin>>t;
    vli h, g;
    lli lhst, lhsn , rhst , rhsn ;
    lli dud_lb, dud_ub , udu_lb, udu_ub;
    bool udu, dud;
    while(t--)
    {
        udu = false ;
        dud = false ;
        q=0;
        cin>>n;
        h= vli(n);
        g= vli(n);
        for(i=0;i<n;i++)
        {
            cin>>h[i];
            cin>>g[i];
        }
        if(n==0)cout<<0<<endl;
        if(n==1)
        {
            cout<<1<<endl;
            cout<<"0 Inf"<<endl;
        }
        else
        {
            //
            //down , up , down case
            //   /\
            //  /  \
            // /    \
            // ______________

            //cout<<" /\\ "<<endl;
            lb=0; ub =inf;impossible =false;
            for(i=0;i < (n-1); i++)
            {
                ubflag=false;lbflag=false;//new
              //  cout<<"i = "<<i<<endl;
                if(i%2 == 0) // this is the 0 < 1 kinda case
                {
                    lhsn = h[i]; lhst = g[i];
                    rhsn = h[i+1] ; rhst = g[i+1];
                }
                else // 1 > 2 kinda case , -- > 2<1
                {
                    lhsn = h[i+1]; lhst = g[i+1];
                    rhsn = h[i] ; rhst = g[i];
                }
                //cout<<lhsn <<" + "<<lhst<<"t  < "<<rhsn<<" + "<<rhst<<"t"<<endl;
                solvelessthan(lhsn, lhst , rhsn , rhst);
                if(impossible)
                    {
                  //      cout<<"This is impossible to continue"<<endl;
                        break;
                    }
                else
                {
                    if(ubflag)
                    {
                    //    cout<<"detected tub = "<<tub<<endl;
                        if(tub<ub)
                        {
                      //      cout<<"updated ub to "<<tub<<endl;
                            ub=tub;
                        }
                    }
                    else if(lbflag)
                    {
                        //cout<<"detected tlb = "<<tlb<<endl;
                        if(tlb>lb)
                        {
                          //  cout<<"updated lb to "<<tlb<<endl;
                            lb= tlb;
                        }
                    }
                }
            }// end of down up down

            //cout<<" done with checking /\\ case"<<endl;
            if(!impossible)
            {
                if(lb<=ub)
                {
                    q++;
                    dud= true ;
                    dud_ub = ub;
                    dud_lb= lb;

              //      cout<<"/\\ --> "<<lb<<" "<<ub<<endl;
                }
            }

            //up down up case
            //0     2
            //\    /
            // \  /
            //  \/
            //  1

            //cout<<"checking \\/  case "<<endl;
            lb=0; ub =inf;impossible =false;
            for(i=0;i < (n-1); i++)
            {
              //  cout<<"i = "<<i<<endl;
                lbflag=false;
                ubflag = false;
                if(i%2 == 1) // this is the 1 > 2  kinda case
                {
                    lhsn = h[i]; lhst = g[i];
                    rhsn = h[i+1] ; rhst = g[i+1];
                }
                else // this is the 0 >  1 case -- > 1<0
                {
                    lhsn = h[i+1]; lhst = g[i+1];
                    rhsn = h[i] ; rhst = g[i];
                }
                //cout<<lhsn <<" + "<<lhst<<"t  < "<<rhsn<<" + "<<rhst<<"t"<<endl;
                solvelessthan(lhsn, lhst , rhsn , rhst);
                if(impossible)
                    {
                  //      cout<<"\\/ case isnt possible"<<endl;
                        break;
                    }
                else
                {
                    if(ubflag)
                    {
                    //    cout<<"detected tub = "<<tub<<endl;
                        if(tub<ub)
                        {
                      //      cout<<"updated ub to "<<tub<<endl;
                            ub=tub;
                        }
                    }
                    else if(lbflag)
                    {
                        //cout<<"detected tlb = "<<tlb<<endl;
                        if(tlb>lb)
                        {
                          //  cout<<"updated lb to "<<tlb<<endl;
                            lb= tlb;
                        }
                    }
                }
            }// end of up down up
            if(!impossible)
            {
                if(lb<=ub)
                {
                    q++;
                    udu=true;
                    udu_ub= ub;
                    udu_lb = lb;

                    //cout<<"\\/ --> "<<lb<<" "<<ub<<endl;
                }
            }

            if(q==0)
                cout<<q<<endl;
            if(q==1)
            {
                cout<<q<<endl;
                if(udu)
                    print(udu_lb, udu_ub);

                else
                    print(dud_lb, dud_ub);
            }
            if(q==2)
            {
                if((udu_ub  + 1)== dud_lb)
                {
                    cout<<1<<endl;
                    print(udu_lb, dud_ub);
                }
                else if((dud_ub + 1) == udu_lb)
                {
                    cout<<1<<endl;
                    print(dud_lb,udu_ub);
                }

                else if(udu_ub<dud_lb)
                {
                    cout<<2<<endl;
                    print(udu_lb, udu_ub);
                    print(dud_lb, dud_ub);
                }

                else
                {
                    cout<<2<<endl;
                    print(dud_lb, dud_ub);
                    print(udu_lb, udu_ub);
                }
            }
        }//end of else
    }
}
void solvelessthan(lli lhsn, lli lhst,lli rhsn, lli rhst)
{
    ubflag= false;
    lbflag = false;
    impossible = false;
    lli tcoeff=lhst- rhst;
    lli ncoeff=rhsn - lhsn;

    if(tcoeff>0)
    {
        // tcoeff * t < ncoeff
        // t < noeff/tcoeff

        ubflag=true;
        // don't use floor function as you are dealing with lli
        if(ncoeff<=0)
        {
            // this is anyway impossible as the upperbound comes out to be negative
            impossible = true ;
            return;
        }
        else if((ncoeff%tcoeff)==0)
        {
            tub= ncoeff/tcoeff - 1;
        }
        else
        {
            tub = ncoeff/tcoeff;
        }


        if(tub<0)
            impossible = true;
    }

    else if(tcoeff<0)
    {
        //tcoeff = - pos
        //  - pos * t < ncoeff
        // t > ncoeff/ (-pos)
        // ==>  t > ncoeff/tcoeff
        // ( lower bound)

        // lhsn + t* lhst < rhsn + t*rhsn

        // case 1 : lhsn < rhsn --> ncoeff>0 --> true for all t>=0
        if(ncoeff>0)return;

        //case2 :  lhsn = rhsn --> ncoeff=0 --> true for all values of t>=1
        if(ncoeff==0)
        {
            lbflag= true;
            tlb = 1;
            return;
        }

        // case3 : lhsn > rhsn --> ncoeff<0 --> figure out!
        lbflag= true;
        if(ncoeff<0)
        {
            // eg. 9 + 2t < 7 + 3t
            // tcoeff = -1 , ncoeff = -2

            //the equation is actually reversed, so lets reverse , it ; no point in dealing with negative numbers
            tcoeff = rhst - lhst;
            ncoeff = lhsn - rhsn;

            // 3t > 4

            tlb = ncoeff/tcoeff + 1;
        }
    }//end of tcoeff<0

    else
    {
        //tcoeff =0
        // lhst = rhst
        // so boils down to ..
        // lhsn < rhsn  i.e.(ncoeff>0)
        if(ncoeff <=0 )
            {
                impossible = true;
                return;
            }
    }
}

