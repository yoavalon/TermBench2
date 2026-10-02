def simulate_thermodynamic_states():
    x, y, z = (1, 1, 1)
    while True:
        x, y, z = (x + y, y + z, z + x)
        print(x, y, z)
simulate_thermodynamic_states()