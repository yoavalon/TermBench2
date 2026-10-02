import numpy as np

def decay_reward(reward, decay_rate, steps):
    return reward * decay_rate ** steps

def calculate_total_reward(initial_reward, decay_rate, max_steps):
    total_reward = 0
    for step in range(max_steps):
        total_reward += decay_reward(initial_reward, decay_rate, step)
    return total_reward

def main():
    initial_reward = 100.0
    decay_rate = 0.95
    max_steps = 1000
    total_reward = calculate_total_reward(initial_reward, decay_rate, max_steps)
    print(total_reward)
main()