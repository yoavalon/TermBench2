def transform_3d_coordinates():
    import math
    while True:
        a, b, c = (1, 2, 3)
        r = math.sqrt(a ** 2 + b ** 2 + c ** 2)
        a, b, c = (a / r, b / r, c / r)
        x, y, z = (0, 0, 0)
        x, y, z = (x + a, y + b, z + c)
        print(x, y, z)
transform_3d_coordinates()