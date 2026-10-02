import numpy as np

def update_reward(state, action):
    if action == 0:
        return state * 0.95
    else:
        return state * 0.9

def simulate_episodes(num_episodes, max_steps):
    rewards = []
    for _ in range(num_episodes):
        state = 1.0
        for _ in range(max_steps):
            action = np.random.randint(2)
            state = update_reward(state, action)
            if state < 0.1:
                break
        rewards.append(state)
    return np.mean(rewards)

def main():
    result = simulate_episodes(100, 1000)
    print(result)
if __name__ == '__main__':
    main()