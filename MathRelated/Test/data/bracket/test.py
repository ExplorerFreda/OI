b = raw_input()
print b[180:200]
ans = 0
for l in xrange(len(b)):
  lis = list()
  for i in range(l, len(b)):
    if b[i] == '}':
      if len(lis)==0 or lis[len(lis)-1] != '{':
        break
      else:
        lis = lis[:-1]
    elif b[i] == ']':
      if len(lis)==0 or lis[len(lis)-1] != '[':
        break
      else:
        lis = lis[:-1]
    elif b[i] == ')':
      if len(lis)==0 or lis[len(lis)-1] != '(':
        break
      else:
        lis = lis[:-1]
    else:
      lis.append(b[i])
    if len(lis) == 0:
	  ans = max(ans, i-l+1)
	  if i-l+1 == 8:
	    print l, i
print ans
