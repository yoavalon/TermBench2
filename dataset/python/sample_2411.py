def simulate_thermodynamic_state(n):
    x, y, z = (1, 1, 1)
    for i in range(n):
        x, y, z = (x + y + z, y + z, z)
    return (x, y, z)
simulate_thermodynamic_state(10)