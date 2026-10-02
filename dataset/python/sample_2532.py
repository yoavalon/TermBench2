import random

def decay_reward(reward, decay_rate):
    return reward * decay_rate

def simulate_reward_decay(initial_reward, decay_rate, steps):
    rewards = []
    current_reward = initial_reward
    for _ in range(steps):
        rewards.append(current_reward)
        current_reward = decay_reward(current_reward, decay_rate)
    return rewards

def main():
    initial_reward = 100.0
    decay_rate = 0.95
    steps = 10
    rewards = simulate_reward_decay(initial_reward, decay_rate, steps)
    for step, reward in enumerate(rewards):
        print(f'Step {step + 1}: Reward {reward:.2f}')
if __name__ == '__main__':
    main()