import random
from datetime import datetime

random.seed(datetime.now().timestamp())
def getloc(current, n):
    loc = (current + random.choice((-1, 1)))
    loc = loc if loc > -1 else 1
    loc = loc if loc < n else n - 2
    return loc

def get_target_sequence(n):
    # Make sure Target starts at an even numbered
    # spot per our assumption
    current_location = random.randrange(0, n, 2)
    seq = [current_location]
    seq_size = 3 * n
    while(seq_size):
        seq_size -= 1
        current_location = getloc(current_location, n)
        seq.append(current_location)
    return seq

def build_solution(dp, n):
    for i in range(n):
        # every run of the loop guarantees
        # that we solved the question for all i < n
        # which build up the solution to N
        if i == 0:
            dp.append(list([0]))
        else:
            dp.append(dp[i - 1] + [i])
    return

n = 12
target_seq  = get_target_sequence(n)
is_shot = False
dp = list()
build_solution(dp, n)
shooter_seq = dp[n - 1]

for i in range(len(shooter_seq)):
    if (shooter_seq[i] == target_seq[i]):
        is_shot = True
        print(f"SHOT!\nShooter sequence till shot: {shooter_seq[0:i+1]}\nTarget sequence till shot: {target_seq[0:i+1]}")
        break

if (not is_shot):
    print(f"NOT SHOT!\nShooter sequence: {shooter_seq}\nTarget sequence: {target_seq}")
#[3, 4, 3, 2, 1, 0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 2]
#[3, 2, 3, 2, 3, 4, 3, 2, 1, 0, 1, 2, 3, 2, 3, 2]
#[3, 4, 3, 4, 3, 4, 3, 2, 1, 0, 1, 2, 1, 0, 1, 2]
