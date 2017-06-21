#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
long long list[50], tot = 0;

long long calc(long long n, long long curr, long long num, long long sgn) {
	if (curr == tot) {
		return n / num * sgn;
	}
	return calc(n, curr + 1, num, sgn) + calc(n, curr + 1, num * list[curr], -sgn);
}

int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	long long n, y;
	cin >> n >> y;
	long long ans = 1;
	for (long long i = 2; i * i <= y; i ++) {
		long long temp = 0;
		while (y % i == 0) {
			temp ++;
			y /= i;
		}
		if (temp)
			list[tot++] = i;
	}
	if (y > 1) {
		list[tot++] = y;
	}
	
	cout << calc(n, 0, 1, 1) << endl;
	return 0;
}