import math
x, y, u, v = map(int, input().split()) 
n = int(input()) 
s = input()
dx = [0,-1,-1,-1, 0, 1, 1, 1]
dy = [1, 1, 0,-1,-1,-1, 0, 1]
d = 0
for c in list(s):
    d = (d + int(c)) % 8 
    x += dx[d]
    y += dy[d] 
    print(x, y)
ans = (u-x)**2 + (y-v)**2
ans = math.sqrt(ans) 
print(ans)