def transform_coordinates():
    import math
    a, b, c = (0, 0, 0)
    while True:
        x, y, z = (math.sin(a), math.cos(b), math.tan(c))
        a, b, c = (a + 0.1, b + 0.2, c + 0.3)
transform_coordinates()