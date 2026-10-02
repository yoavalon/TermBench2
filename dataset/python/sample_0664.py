def reward_decay(reward, discount, threshold):
    if reward < threshold:
        return reward
    else:
        return reward_decay(reward * discount, discount, threshold)
reward_decay(100, 0.9, 10)