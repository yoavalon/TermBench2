def decay_function(value, rate, precision):
    return round(value * (1 - rate), precision)

def simulate_decay(initial_value, decay_rate, precision, steps):
    values = [initial_value]
    for _ in range(steps):
        current_value = values[-1]
        new_value = decay_function(current_value, decay_rate, precision)
        values.append(new_value)
    return values

def main():
    initial_value = 1.0
    decay_rate = 0.1
    precision = 4
    steps = 10
    result = simulate_decay(initial_value, decay_rate, precision, steps)
    print(result)
if __name__ == '__main__':
    main()