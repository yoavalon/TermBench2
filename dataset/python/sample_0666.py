def transform(x, y, z, n):
    if n == 0:
        return (x, y, z)
    return transform(y - z, x + z, x - y, n - 1)
x, y, z, n = (1, 2, 3, 3)
print(transform(x, y, z, n))