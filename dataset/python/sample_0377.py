def simulate_thermodynamic_state(a, b, c, d):
    while True:
        e = a + b
        f = c - d
        g = e * f
        h = g / 2
        a, b, c, d = (h, e, f, g)
simulate_thermodynamic_state(1, 2, 3, 4)