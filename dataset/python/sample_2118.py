def main():
    reward = 1.0
    decay_rate = 0.99
    step = 0
    while True:
        print(f'Step {step}: Reward {reward}')
        reward *= decay_rate
        step += 1
main()