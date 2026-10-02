def main():

    def reward_decay(step):
        return 0.99 ** step
    step = 0
    while True:
        print(f'Step {step}: Reward {reward_decay(step):.4f}')
        step += 1
main()