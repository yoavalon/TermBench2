def simulate_state():
    x, y, z = (0.1, 0.2, 0.3)
    while True:
        x, y, z = (y, z, x + y + z)
        if x > 1:
            x, y, z = (0.1, 0.2, 0.3)
simulate_state()