#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9+7;
int main()
{
	char s[111111];
	long long i,sum,n;
	long long pow26[111111];
	long long f[111111];
	long long g[111111];
	scanf("%s",s);
	pow26[0]=1;
	for(i=1;i<111111;i++)
		pow26[i] = (pow26[i-1]*26)%M;
	for(i=0;s[i]!='\0';i++)
	{
		g[i]='Z' - s[i];
	}
	n=i;
	f[n-1]=1;
	//f[n-2]=1+g[n-1];
	for(i=n-2;i>=0;i--)
	{
		f[i] = (((f[i+1]-1)*26)%M + g[i+1] + 1)%M;
		if(f[i]<0)
			f[i]+=M;
	}
	sum =0;
	for(i=0;i<n;i++)
	{
		sum = (sum + (g[i]*f[i])%M)%M;
	}
	printf("%lld\n",sum);
	return 0;
}
