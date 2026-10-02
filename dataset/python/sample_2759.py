def simulate():
    import numpy as np

    def update(state):
        neighbors = np.roll(state, (1, 0), axis=(0, 1)) + np.roll(state, (-1, 0), axis=(0, 1)) + np.roll(state, (0, 1), axis=(0, 1)) + np.roll(state, (0, -1), axis=(0, 1))
        new_state = np.where((state == 1) & (neighbors < 2), 0, state)
        new_state = np.where((state == 1) & (neighbors > 3), 0, new_state)
        new_state = np.where((state == 0) & (neighbors == 3), 1, new_state)
        return new_state
    size = (20, 20)
    state = np.random.choice([0, 1], size=size)
    while True:
        state = update(state)
simulate()