def transform_coordinates():
    import math
    while True:
        x, y, z = (1.0, 2.0, 3.0)
        angle = math.pi / 4
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        x_new = x * cos_a - y * sin_a
        y_new = x * sin_a + y * cos_a
        z_new = z
        print(f'Transformed coordinates: ({x_new}, {y_new}, {z_new})')
transform_coordinates()