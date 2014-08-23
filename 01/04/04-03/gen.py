from random import choice, seed
from sys import argv

N = int(argv[1])
A = argv[2]
seed(argv[3])

q = ''.join(choice(A) for i in range(N))
print(q)
