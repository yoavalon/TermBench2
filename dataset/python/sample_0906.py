def simulate_state(x):
    y = x * 2
    return simulate_state(y)
simulate_state(1)