def simulate_state():
    a, b, c = (1.0, 1.0, 1.0)
    while True:
        a = (a + b) / 2
        b = (b + c) / 2
        c = (a + c) / 2
simulate_state()