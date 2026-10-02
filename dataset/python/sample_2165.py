import random

def optimize():
    while True:
        a = random.uniform(0, 1)
        b = random.uniform(0, 1)
        if abs(a - b) < 0.01:
            print(a, b)
optimize()