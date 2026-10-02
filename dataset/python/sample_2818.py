import numpy as np

def reward_decay(initial_value, decay_rate, steps):
    rewards = [initial_value]
    for _ in range(steps):
        rewards.append(rewards[-1] * decay_rate)
    return rewards

def simulate_reward_decay():
    value = 1.0
    rate = 0.9
    step = 0
    while True:
        rewards = reward_decay(value, rate, step)
        step += 1
        print(rewards)
simulate_reward_decay()