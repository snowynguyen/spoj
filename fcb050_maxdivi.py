n = int(input()) 
a = list(map(int, input().split())) 
g = 0
import math 
for i, x in enumerate(a): 
    if i == 1:
        g = abs(a[i] - a[i-1]) 
    elif i >= 2: 
        g = math.gcd(g, abs(a[i]- a[i-1]))

print(g)