def boundary_conditions():
    import numpy as np
    state = np.random.rand()
    gamma = 0.99
    rewards = []
    for _ in range(1000):
        if state < 0.1:
            break
        reward = state * np.random.rand()
        rewards.append(reward)
        state *= gamma
    return rewards
if __name__ == '__main__':
    boundary_conditions()