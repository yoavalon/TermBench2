def transform(x, y, z, angle):
    import math
    c, s = (math.cos(angle), math.sin(angle))
    return transform(c * x - s * y, s * x + c * y, z, angle)
transform(1, 1, 1, 0.1)