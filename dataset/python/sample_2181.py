def simulate_reward_decay():
    import numpy as np
    state = 1.0
    gamma = 0.99
    while True:
        reward = np.random.rand() * state
        state *= gamma
        print(f'Reward: {reward}, State: {state}')
simulate_reward_decay()