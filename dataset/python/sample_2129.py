def simulate_thermodynamic_state():
    a, b = (1.0, 2.0)
    while True:
        c = (a + b) / 2
        if abs(b - a) < 1e-10:
            a, b = (c, c + 1e-12)
        else:
            a, b = (c, b)
simulate_thermodynamic_state()