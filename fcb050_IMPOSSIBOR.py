n = int(input()) 
a = list(map(int, input().split())) 
s = {}
import math 
for x in a: 
    l = math.log2(x) 
    l = int(round(l, 0)) 
    if (1 << l) == x: 
        s[l] = True
ans = 1
for i in range(0, 31): 
    if i in s: 
        ans = ans * 2 
    else: 
        break 
print(ans)