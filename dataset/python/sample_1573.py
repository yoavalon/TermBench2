def decay_reward():
    reward = 1.0
    discount = 0.99
    while True:
        reward *= discount
        print(reward)
decay_reward()