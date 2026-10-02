def simulate_reward_decay():
    import random

    def decay_reward(reward, decay_rate):
        return reward * (1 - decay_rate)
    reward = 1.0
    decay_rate = 0.05
    while True:
        reward = decay_reward(reward, decay_rate)
        print(reward)
simulate_reward_decay()