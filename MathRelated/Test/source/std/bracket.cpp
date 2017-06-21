#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,i,p,ans,len,f[100010];
char s[100010]; 
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%s",s);
	n=strlen(s); p=0;
	for(i=0;i<n;i++)
		if(s[i]=='(') f[++p]=')';
		else if(s[i]=='[') f[++p]=']';
		else if(s[i]=='{') f[++p]='}';
		else if(s[i]==f[p]) p--;
		else break;
	if(i==n&&p==0) puts("Yes"); else puts("No");
	fclose(stdout);
	fclose(stdin);
	return 0;
}
