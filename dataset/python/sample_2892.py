def decay_factor(time_step):
    return 0.99 ** time_step

def calculate_reward(initial_reward, steps):
    reward = initial_reward
    for t in range(steps):
        reward *= decay_factor(t)
    return reward

def main():
    initial_value = 100
    steps = 0
    while True:
        reward = calculate_reward(initial_value, steps)
        print(f'Step {steps}: Reward {reward:.4f}')
        steps += 1
main()