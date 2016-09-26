//Nilanjana Lodh
#include <bits/stdc++.h>
#define pi M_PI
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

const lli inf= 9000000000000;
const lli mod= 1000000007;

inline double to_degrees(double radians) {
    return radians * (180.0 / pi);
}
double dist2(double x1 ,double y1 , double x2 , double y2)
{
    double x = (x1 - x2);
    double y = (y1 - y2);

    return x*x + y*y ;
}

double dist(double x1 ,double y1 , double x2 , double y2)
{
    double x = (x1 - x2);
    double y = (y1 - y2);

    return sqrt(x*x + y*y) ;
}
double fplus(int x, int y, int r ,int x1)
{
     return y + sqrt(r*r - (x-x1)*(x-x1));
}
double fminus(int x, int y, int r ,int x1)
{
     return y - sqrt(r*r - (x-x1)*(x-x1));
}
double rtri_area(double x1, double y1, double x2 , double y2 , double x3 , double y3)
{
    double d1 = dist(x2,y2, x3, y3);
    double d2 = dist(x1,y1, x3, y3);
    double d3 = dist(x2,y2, x1, y1);

    double md =max(d1, max(d2,d3));
    if(md == 1)
        return 0.5 * d2 * d3 ;

    if(md == 2)
        return 0.5 * d3 * d1 ;

    return 0.5 * d1 * d2 ;
}

double sec_angle(double x, double y , double r , double x1 , double y1 , double x2 , double y2)
{
    double d = dist(x1, y1, x2, y2);
    return acos(0.5*d / r);
}

double sec_area(double r, double angle)
{
    return angle*r*r;
}

double seg_area(double x, double y, double r, double x1, double y1 , double x2, double y2)
{
    double angle = sec_angle(x,y,r,x1,y1,x2,y2);

    double secar = sec_area(r, angle);

    double midx = 0.5 *(x1+ x2);
    double midy = 0.5 *(y1 + y2);

    double triar= 2*rtri_area(midx, midy , x1,y1, x, y);

    return secar - triar ;
}
double intersect_area(double x, double y , double r , double x1, double y1 , double x2 , double y2)
{
    if(x1<=(x-r) && (y1<=(y-r)) && (x2>=(x+r)) && (y2>=(y+r)))
        return pi*r*r ;

    double sx1 , sx2 , sy1 , sy2 ;

    sx1 = (x1 - x);
    sx2 = (x2 - x);
    sy1 = (y1 - y);
    sy2 = ( y2 - y);

    if(sx1 > 0 && sy1>0)
    {
        if(dist2(x,y,x1,y1)>=r*r)
            return 0;
    }

    if(sx1>0 && sy2<0)
    {
        if(dist2(x,y,x1,y2)>=r*r)
            return 0;
    }

    if(sx2<0 && sy2<0)
    {
        if(dist2(x,y,x2,y2)>=r*r)
            return 0;
    }

    if(sx2<0 && sy1>0)
    {
        if(dist2(x,y,x2,y1)>=r*r)
            return 0;
    }

    double d1 , d2 , d3 , d4;
    d1 = dist(x,y,x1,y1);
    d2 = dist(x,y,x2,y1);
    d3 = dist(x,y,x2,y2);
    d4 = dist(x,y,x1,y2);

    bool b1, b2, b3, b4 ;
    b1 = d1 <r ;
    b2 = d2 <r ;
    b3 = d3 <r ;
    b4 = d4 <r ;


    int v = b1 + b2 + b3 + b4 ;

    int px1, py1, px2 ,py2 , px3 , py3 ;
    if((d1<=r) && (d2<=r) && (d3<=r) && (d4<=r))
    return (x2-x1)*(y2-y1);

    if(v==3)
    {
        if(!b3)
        {

        }
    }

    if(v==2)
    {

    }

    if(v==1)
    {
        if(b1)
        {
            px1 = x1; py1 = y1;
            py2 = y1;
            if(sy1>0)
                px2 = fplus(y,x,r,py2);

            else
                px2 = fminus(y,x,r,py1);

        }
    }

}
