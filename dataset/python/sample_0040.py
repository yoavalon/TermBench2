def simulate_thermodynamic_state():
    x, y, z = (0, 0, 0)
    while x < 10:
        x += 1
        y += x
        z += y
    return z
simulate_thermodynamic_state()