from random import choice
import random

alph = 'ab'
L1 = random.randint(1, 5)
L2 = random.randint(1, 5)
S1 = [choice(alph) for i in range(L1)]
S2 = [choice(alph) for i in range(L2)]
print(''.join(S1))
print(''.join(S2))
