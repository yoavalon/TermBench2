def optimize():
    x, v, p, g = (0, 0, 0, 0)
    for _ in range(100):
        x = x + v
        v = v + (p - x) + (g - x)
        if x > 10:
            break
    return x
optimize()