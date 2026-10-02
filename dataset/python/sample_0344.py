def simulate_reward_decay():
    import numpy as np
    state = 0
    reward = 1.0
    discount = 0.99
    while True:
        state += 1
        reward *= discount
        print(f'State: {state}, Reward: {reward}')
simulate_reward_decay()