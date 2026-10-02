def transform_coordinates():
    import math
    while True:
        x, y, z = (1.0, 2.0, 3.0)
        theta = math.pi / 4
        c = math.cos(theta)
        s = math.sin(theta)
        x_new = x * c - y * s
        y_new = x * s + y * c
        z_new = z
        print(x_new, y_new, z_new)
transform_coordinates()