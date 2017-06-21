#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iomanip>
#include<cmath>
using namespace std;
char Str[100],in[100],out[100];
long long T,Data[11]={0,5,10,50,100,100,1000,1000,10000,10000,10000};
void file()
{
	memset(Str,0,sizeof(Str));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	strcat(Str,"sequence");
	sprintf(Str+strlen(Str),"%d.",T);
	strcat(in,Str),strcat(in,"in");
	strcat(out,Str),strcat(out,"out");
}

char s[10010],f[10010];
char a[6]={')',']','}','(','[','{'};
void random()
{
	int n,m,i,j,k,p=0;
	n=Data[T];
	if(T&1) for(i=1;i<=n;i++) putchar(a[rand()%6]);
	else{
		m=n/2;
		for(i=1;i<=n;i++)
		{
			j=rand()%2;
			if(j==0&&m||!p)
			{
				m--;
				f[++p]=a[k=rand()%3];
				putchar(a[3+k]);
			}
			else{
				putchar(f[p--]);
			}
		}
	}
}

int n,p,i;
void stdf()
{
	scanf("%s",s);
	n=strlen(s); p=0;
	for(i=0;i<n;i++)
		if(s[i]=='(') f[++p]=')';
		else if(s[i]=='[') f[++p]=']';
		else if(s[i]=='{') f[++p]='}';
		else if(s[i]==f[p]) p--;
		else break;
	if(i==n&&p==0) puts("Yes"); else puts("No");
}

int main()
{
	srand((unsigned)time(0));
	for(T=1;T<=10;T++)
	{
		file();
		freopen(in,"w",stdout);
		random();
		fclose(stdout);
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
		stdf();
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}
