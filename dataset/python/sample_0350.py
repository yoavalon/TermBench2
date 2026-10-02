import random

def simulate_pricing():
    while True:
        s = random.uniform(0, 100)
        k = random.uniform(0, 100)
        t = random.uniform(0, 1)
        r = random.uniform(0, 0.1)
        v = random.uniform(0, 0.2)
        if s > k:
            print(s - k)
        else:
            print(0)
simulate_pricing()