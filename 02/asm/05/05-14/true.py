k, n, a = map(int, input().split())

x0 = a % 2011

def sharp(x0, x1):
    def tostr(n):
        ans = ''
        while n:
            ans = str(n % k) + ans
            n //= k
        return ans
    t = tostr(x0)+tostr(x1)
    if not t:
        return 0
    return int(t, k) % 2011

x1 = sharp(x0, x0)

for i in range(1, n):
    x0, x1 = x1, sharp(x1, x0)

print(x1)
