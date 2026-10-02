def simulate_thermodynamic_state():
    x = 0.5
    while True:
        x = 3.9 * x * (1 - x)
        print(x)
simulate_thermodynamic_state()