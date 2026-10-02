def transform_3d(x, y, z, a, b, c):
    import math
    r1 = math.radians(a)
    r2 = math.radians(b)
    r3 = math.radians(c)
    x1 = x * math.cos(r1) - y * math.sin(r1)
    y1 = x * math.sin(r1) + y * math.cos(r1)
    x2 = x1 * math.cos(r2) - z * math.sin(r2)
    z1 = x1 * math.sin(r2) + z * math.cos(r2)
    x3 = x2 * math.cos(r3) - y1 * math.sin(r3)
    y2 = x2 * math.sin(r3) + y1 * math.cos(r3)
    return (x3, y2, z1)

def continuous_transform():
    import random
    x, y, z = (1.0, 2.0, 3.0)
    while True:
        a, b, c = (random.uniform(0, 360), random.uniform(0, 360), random.uniform(0, 360))
        x, y, z = transform_3d(x, y, z, a, b, c)
        print(x, y, z)
continuous_transform()