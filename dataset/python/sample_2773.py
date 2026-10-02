def main():
    import random
    reward = 100
    decay_rate = 0.99
    while True:
        action = random.choice(['forward', 'backward', 'left', 'right'])
        if action == 'forward':
            reward *= decay_rate
        print(f'Action: {action}, Reward: {reward}')
main()