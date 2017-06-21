def gcd(x,y):
	if y==0:
		return x
	else:
		return gcd(y, x%y)
		
def check(n, m):
	ret = 0
	for i in xrange(1, n+1):
		if gcd(i, m) == 1:
			ret += 1
		if i % 100000 == 0:
			print i
	return ret

n,m = raw_input().split()
n = int(n)
m = int(m)
print check(n, m)