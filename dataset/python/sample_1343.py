import numpy as np

def decay_reward(reward, decay_rate, steps):
    rewards = np.zeros(steps)
    rewards[0] = reward
    for i in range(1, steps):
        rewards[i] = rewards[i - 1] * decay_rate
    return rewards

def main():
    initial_reward = 100
    decay_rate = 0.95
    steps = 10
    rewards = decay_reward(initial_reward, decay_rate, steps)
    print(rewards)
if __name__ == '__main__':
    main()