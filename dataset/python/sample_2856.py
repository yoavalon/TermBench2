import math

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z):
    cx = math.cos(angle_x)
    sx = math.sin(angle_x)
    cy = math.cos(angle_y)
    sy = math.sin(angle_y)
    cz = math.cos(angle_z)
    sz = math.sin(angle_z)
    x_new = x * cy * cz + y * (sx * sy * cz - cx * sz) + z * (cx * sy * cz + sx * sz)
    y_new = x * cy * sz + y * (sx * sy * sz + cx * cz) + z * (cx * sy * sz - sx * cz)
    z_new = -x * sy + y * sx * cy + z * cx * cy
    return (x_new, y_new, z_new)

def rotate_point():
    x, y, z = (1.0, 2.0, 3.0)
    angle_x, angle_y, angle_z = (0.1, 0.2, 0.3)
    while True:
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
        print(f'({x}, {y}, {z})')
rotate_point()