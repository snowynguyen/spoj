n = int(input()) 
prev = 0
while (n > 0): 
    a = int(input()) 
    cur = 0 
    while a >= 9: 
        cur = 10 * cur + 9 
        a -= 9 
    if a > 0: 
        cur = 10 * cur + a 
    while cur <= prev:
        cur = cur * 10 
    print(cur)
    prev = cur
    n -= 1