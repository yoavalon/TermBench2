import random

def simulate():
    state = [0.5, 0.5, 0.5]
    while True:
        for i in range(3):
            state[i] += random.uniform(-0.1, 0.1)
            state[i] = max(0, min(1, state[i]))
        print(state)
simulate()