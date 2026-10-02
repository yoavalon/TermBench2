def simulate_thermodynamic_state():
    x = 0.0
    while True:
        x += 0.0001
        y = 1 / x
        if y == 0:
            break
simulate_thermodynamic_state()