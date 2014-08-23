import random

N = 5
M = 3

print(N, M)

A = [i+1 for i in range(N)]

for i in range(M):
    pi,pj = random.randint(1, N), random.randint(1, N)
    i = A.index(pi)
    j = A.index(pj)
    if (i > j): 
        i,j = j,i
        pi, pj = pj, pi
    A = A[i:j+1] + A[:i] + A[j+1:]
    print(pi, pj)
