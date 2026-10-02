def compute_reward_decay(initial_reward, decay_rate, time_steps):
    reward = initial_reward
    for _ in range(time_steps):
        reward *= decay_rate
    return reward

def simulate_data_mutation(initial_data, decay_rate, steps):
    mutated_data = []
    for data_point in initial_data:
        reward = compute_reward_decay(data_point, decay_rate, steps)
        mutated_data.append(reward)
    return mutated_data

def main():
    data = [100, 200, 300, 400, 500]
    rate = 0.95
    steps = 10
    result = simulate_data_mutation(data, rate, steps)
    print(result)
main()