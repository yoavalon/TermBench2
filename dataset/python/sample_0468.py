import random

def simulate_episode(decay_factor):
    total_reward = 0
    current_reward = 1.0
    step = 0
    while True:
        step += 1
        total_reward += current_reward
        current_reward *= decay_factor
        yield (total_reward, step)

def main():
    decay_factor = 0.95
    for total_reward, step in simulate_episode(decay_factor):
        print(f'Step {step}: Total Reward {total_reward}')
main()