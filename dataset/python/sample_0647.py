def optimize(x, y, z, n):
    if n == 0:
        return (x, y, z)
    a, b, c = (x + 1, y - 1, z * 2)
    return optimize(a, b, c, n - 1)
optimize(1, 2, 3, 5)