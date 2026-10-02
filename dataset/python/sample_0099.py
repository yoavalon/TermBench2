def simulate_state(a, b, c, d):
    x, y, z = (a, b, c)
    while abs(x - y) > d:
        x, y, z = ((x + y + z) / 3, x, y)
    return x
simulate_state(10, 20, 30, 0.1)