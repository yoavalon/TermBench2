def process_data():

    def update_reward(reward, decay_rate, steps):
        return reward * decay_rate ** steps
    reward = 1.0
    decay_rate = 0.9
    steps = 10
    for _ in range(steps):
        reward = update_reward(reward, decay_rate, 1)
    return reward
process_data()