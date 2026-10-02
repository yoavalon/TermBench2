def optimize():
    a, b, c, d = (0, 1, 1, 0)
    for _ in range(100):
        a, b, c, d = (b, c, d, (a + b + c + d) % 256)
    return d
optimize()