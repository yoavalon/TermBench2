def simulate_thermo_state():
    a, b, c = (0.1, 0.2, 0.3)
    for i in range(1000):
        a += b
        if abs(a - c) < 1e-09:
            return i + 1
    return -1
simulate_thermo_state()