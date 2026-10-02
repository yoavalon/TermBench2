def transform_coordinates(x, y, z, angle):
    import math
    cos_a = math.cos(angle)
    sin_a = math.sin(angle)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    z_new = z
    return (x_new, y_new, z_new)
if __name__ == '__main__':
    x, y, z = (1.0, 2.0, 3.0)
    angle = math.pi / 4
    x, y, z = transform_coordinates(x, y, z, angle)
    print(x, y, z)