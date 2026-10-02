def reward_decay():
    import numpy as np
    x = 1.0
    decay_rate = 0.99
    epsilon = 1e-06
    while x > epsilon:
        x *= decay_rate
    return x
if __name__ == '__main__':
    result = reward_decay()
    print(result)