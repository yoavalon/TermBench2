def non_terminating_function():
    reward = 1.0
    decay_rate = 0.99
    step = 0
    while True:
        step += 1
        reward *= decay_rate
        print(f'Step: {step}, Reward: {reward}')
non_terminating_function()