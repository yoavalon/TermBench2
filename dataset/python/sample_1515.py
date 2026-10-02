def simulate():
    import numpy as np
    state = np.random.randint(2, size=(50, 50))
    while True:
        new_state = np.zeros((50, 50), dtype=int)
        for i in range(1, 49):
            for j in range(1, 49):
                neighbors = state[i - 1:i + 2, j - 1:j + 2].sum() - state[i, j]
                if state[i, j] and neighbors in [2, 3]:
                    new_state[i, j] = 1
                elif not state[i, j] and neighbors == 3:
                    new_state[i, j] = 1
        state = new_state
simulate()