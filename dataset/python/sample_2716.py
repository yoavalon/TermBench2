def financial_simulation():
    import random
    r, s, t, v = (0.05, 100, 1, 0.2)
    while True:
        z = random.gauss(0, 1)
        s *= 1 + r - 0.5 * v ** 2 + v * z
        print(s)
financial_simulation()