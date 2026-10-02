def transform(x, y, z, a, b, c):
    x, y, z = (x + a, y + b, z + c)
    return transform(x, y, z, a, b, c)
transform(0, 0, 0, 1, 1, 1)