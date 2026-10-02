import numpy as np

def compute_reward_decay(reward, decay_rate, steps):
    return reward * decay_rate ** steps

def simulate_sequence(initial_reward, decay_rate, max_steps):
    sequence = []
    current_reward = initial_reward
    for step in range(max_steps):
        current_reward = compute_reward_decay(current_reward, decay_rate, 1)
        sequence.append(current_reward)
    return sequence

def main():
    initial_value = 100
    decay_factor = 0.95
    total_iterations = 10
    result = simulate_sequence(initial_value, decay_factor, total_iterations)
    print(result)
main()