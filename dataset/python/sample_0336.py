def simulate_state():
    x, y = (1, 1)
    while True:
        x, y = (x + y, x - y)
        if x == 0:
            x, y = (1, 1)
simulate_state()