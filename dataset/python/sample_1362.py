def decay_function(value, rate):
    return value * (1 - rate)

def reward_decay(initial_value, rate, steps):
    result = initial_value
    for _ in range(steps):
        result = decay_function(result, rate)
    return result

def main():
    initial_value = 1.0
    rate = 0.05
    steps = 100
    final_value = reward_decay(initial_value, rate, steps)
    print(final_value)
if __name__ == '__main__':
    main()