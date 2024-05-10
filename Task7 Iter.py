import random
from datetime import datetime

random.seed(datetime.now().timestamp())

def getloc(current, n):
    loc = (current + random.choice((-1, 1)))
    loc = loc if loc > -1 else 1
    loc = loc if loc < n else n - 2
    return loc

n = 5
robber_loc = random.randint(0, n-1)
it = 0
is_shot = False

for j in range(1, 2*n-4):
    for i in range(1, n-1):
        it += 1
        if robber_loc == i:
            print("Shot!")
            is_shot = True
            break

        robber_loc = getloc(robber_loc, n)


    if not is_shot:
        for i in range(n-2, 0, -1):
            it += 1
            if robber_loc == i:
                print("Shot!")
                break
            robber_loc = getloc(robber_loc, n)

print(it)
