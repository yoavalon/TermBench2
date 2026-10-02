def simulate_state(n):
    a, b = (0, 1)
    for _ in range(n):
        a, b = (b, a + b)
    return a
simulate_state(10)