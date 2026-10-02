def simulate_state():
    x, y = (0, 1)
    while True:
        x, y = (y, x + y)
simulate_state()