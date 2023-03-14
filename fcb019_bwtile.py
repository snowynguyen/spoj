m, n, k = map(int, input().split()) 
odd = (m*n) % 2
ret = 0 
if odd == 1: 
    if abs(m * n- k * 2) == 1: 
        ret = 1
else: 
    if m * n == k * 2: 
        ret = 2 
print(ret)