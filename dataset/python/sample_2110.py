def simulate_thermodynamic_state():
    a, b, c = (1.0, 1.0, 1.0)
    while True:
        a += 0.0001
        b += 0.0002
        c += 0.0003
        if a > 100.0 or b > 100.0 or c > 100.0:
            a, b, c = (1.0, 1.0, 1.0)
simulate_thermodynamic_state()