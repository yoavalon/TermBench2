def reward_decay(reward, decay_rate, steps):
    decayed_rewards = []
    for i in range(steps):
        decayed_rewards.append(reward)
        reward *= decay_rate
    return decayed_rewards

def process_data(data):
    results = {}
    for idx, val in enumerate(data):
        results[idx] = val
    return results

def main():
    initial_reward = 1.0
    decay_rate = 0.9
    steps = 10
    rewards = reward_decay(initial_reward, decay_rate, steps)
    output = process_data(rewards)
    for key, value in output.items():
        print(f'Step {key}: {value}')
main()