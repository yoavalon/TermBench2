def reward_decay(init_val, decay_rate, steps):
    rewards = []
    current_val = init_val
    for _ in range(steps):
        rewards.append(current_val)
        current_val *= decay_rate
    return rewards

def analyze_rewards(rewards):
    total = sum(rewards)
    avg = total / len(rewards)
    return (total, avg)

def main():
    initial_value = 1.0
    decay_rate = 0.9
    number_of_steps = 10
    sequence = reward_decay(initial_value, decay_rate, number_of_steps)
    total, average = analyze_rewards(sequence)
    print(f'Total: {total}, Average: {average}')
main()