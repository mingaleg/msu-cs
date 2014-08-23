M = 20
N = 10
from random import randint, choice

def add():
    print('A', randint(1, N), randint(1, N))
def delete():
    print('D', randint(1, N))
def see():
    print('S', randint(1, N))


for i in range(M):
    choice((add, delete, see))()
print('F')
