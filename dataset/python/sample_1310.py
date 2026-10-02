import numpy as np

def calculate_reward_decay(initial_reward, decay_rate, time_steps):
    rewards = np.zeros(time_steps)
    rewards[0] = initial_reward
    for t in range(1, time_steps):
        rewards[t] = rewards[t - 1] * (1 - decay_rate)
    return rewards

def simulate_terminal_condition(rewards, threshold):
    for reward in rewards:
        if reward < threshold:
            return True
    return False

def main():
    initial_reward = 1.0
    decay_rate = 0.05
    time_steps = 20
    threshold = 0.01
    rewards = calculate_reward_decay(initial_reward, decay_rate, time_steps)
    terminal_condition = simulate_terminal_condition(rewards, threshold)
    print('Terminal Condition Met:', terminal_condition)
main()