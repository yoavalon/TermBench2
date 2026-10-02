def calculate_reward_decay(initial_reward, decay_rate, steps):
    rewards = []
    current_reward = initial_reward
    for _ in range(steps):
        rewards.append(current_reward)
        current_reward *= decay_rate
    return rewards

def update_environment(rewards):
    while True:
        for reward in rewards:
            print(reward)
        rewards = calculate_reward_decay(rewards[-1], 0.95, 10)

def main():
    initial_reward = 100
    decay_rate = 0.95
    steps = 10
    rewards = calculate_reward_decay(initial_reward, decay_rate, steps)
    update_environment(rewards)
main()