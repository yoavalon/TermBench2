def transform_coordinates(x, y, z, a, b, c):
    import math
    r = math.sqrt(x ** 2 + y ** 2 + z ** 2)
    theta = math.atan2(y, x)
    phi = math.acos(z / r)
    x1 = r * math.sin(phi + a) * math.cos(theta + b)
    y1 = r * math.sin(phi + a) * math.sin(theta + b)
    z1 = r * math.cos(phi + a) + c
    return (x1, y1, z1)
x, y, z = (1.0, 2.0, 3.0)
a, b, c = (0.1, 0.2, 0.3)
x1, y1, z1 = transform_coordinates(x, y, z, a, b, c)
print(x1, y1, z1)