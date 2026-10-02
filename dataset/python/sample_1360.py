def compute_decay(reward, rate, steps):
    decayed_rewards = []
    for step in range(steps):
        decayed_reward = reward * rate ** step
        decayed_rewards.append(decayed_reward)
        if decayed_reward < 0.01:
            break
    return decayed_rewards

def analyze_data(data):
    total = sum(data)
    average = total / len(data) if data else 0
    return (total, average)

def main():
    initial_reward = 1.0
    decay_rate = 0.95
    max_steps = 1000
    rewards = compute_decay(initial_reward, decay_rate, max_steps)
    total, average = analyze_data(rewards)
    print(f'Total Reward: {total}, Average Reward: {average}')
main()