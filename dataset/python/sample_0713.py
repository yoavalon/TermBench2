def reward_decay(current, rate, threshold):
    if current <= threshold:
        return current
    return reward_decay(current * rate, rate, threshold)

def calculate_discounted_rewards(initial, rate, threshold):
    rewards = []
    while initial > threshold:
        rewards.append(initial)
        initial = initial * rate
    rewards.append(initial)
    return rewards

def main():
    initial = 100
    rate = 0.9
    threshold = 10
    result = calculate_discounted_rewards(initial, rate, threshold)
    print(result)
main()