import random

n = int(raw_input())
print n
for i in range(n+1):
	s = ''
	for j in range(n):
		s += '%.6f'%(random.randint(0, 40000) / 2.0)
		if j != n-1:
			s += ' '
	print s
