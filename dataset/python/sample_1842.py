def simulate_thermo_state():
    x, y, z = (0.0, 0.0, 0.0)
    for i in range(1000):
        x += 0.0001
        y -= 0.0001
        z = (x + y) * 10000
    return z
simulate_thermo_state()