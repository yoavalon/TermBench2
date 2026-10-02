def decay_reward(reward, decay_rate, steps):
    for _ in range(steps):
        reward *= decay_rate
    return reward

def process_data(data, rate, iterations):
    results = []
    for item in data:
        results.append(decay_reward(item, rate, iterations))
    return results

def main():
    data = [1.0, 2.0, 3.0, 4.0, 5.0]
    rate = 0.95
    iterations = 10
    output = process_data(data, rate, iterations)
    print(output)
main()