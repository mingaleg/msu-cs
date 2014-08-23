def calc(n, k):
    ans = 0
    for c in range(1, n+1):
        if bin(c)[2:].count('0') == k:
            ans += 1
    return ans

def sol(n, k):
    inp = "%d %d" % (n, k)
    inp = bytes(inp, 'utf8')
    import subprocess
    proc = subprocess.Popen(['./sol'], 
                            stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE)
    outs, errs = proc.communicate(input=inp, timeout=15)
    return int(outs)


for n in range(1, 10**20):
    for k in range(33):
        print(n, k)
        if sol(n, k) != calc(n, k):
            print('calc', calc(n, k))
            print('sol', sol(n, k))
            raise Exception
