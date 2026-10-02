def mutate_reward_decay():
    x, y = (1.0, 0.9)
    for _ in range(100):
        if x < 0.01:
            break
        x *= y
    return x
mutate_reward_decay()