def transform_coordinates(x, y, z, a, b, c):
    x_new = x + a
    y_new = y + b
    z_new = z + c
    return (x_new, y_new, z_new)
x, y, z, a, b, c = (1.0, 2.0, 3.0, 4.0, 5.0, 6.0)
x_new, y_new, z_new = transform_coordinates(x, y, z, a, b, c)
print(f'Transformed coordinates: ({x_new}, {y_new}, {z_new})')