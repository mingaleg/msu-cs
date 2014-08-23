from random import randint
from sys import argv

N = int(argv[1])

X = [randint(-10, 10) for i in range(N)]

M = [[randint(-10, 10) for i in range(N)] for j in range(N)]
S = [sum(X[j]*M[i][j] for j in range(N)) for i in range(N)]

print(N)
for i in range(N):
    print(' '.join(str(x) for x in M[i]), end = ' ')
    print(S[i])
