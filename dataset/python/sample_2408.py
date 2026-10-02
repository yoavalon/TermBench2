def simulate_decay(steps, decay_rate, initial_value):
    value = initial_value
    results = []
    for _ in range(steps):
        results.append(value)
        value *= decay_rate
    return results

def main():
    steps = 10
    decay_rate = 0.9
    initial_value = 100
    result = simulate_decay(steps, decay_rate, initial_value)
    print(result)
main()