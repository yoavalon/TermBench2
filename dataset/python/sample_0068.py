def transform_coordinates(x, y, z):
    a = x + 2 * y - z
    b = 3 * x - y + 2 * z
    c = -x + y + 3 * z
    return (a, b, c)
result = transform_coordinates(1, 2, 3)
print(result)