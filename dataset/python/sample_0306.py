import numpy as np

def simulate_decay():
    state = np.random.rand()
    while True:
        reward = state * np.exp(-state)
        state -= 0.01
        if state < 0:
            state = 0
simulate_decay()