def transform_coordinates(x, y, z, angle_x, angle_y, angle_z):
    import math
    cos_x = math.cos(angle_x)
    sin_x = math.sin(angle_x)
    cos_y = math.cos(angle_y)
    sin_y = math.sin(angle_y)
    cos_z = math.cos(angle_z)
    sin_z = math.sin(angle_z)
    x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    return (x_new, y_new, z_new)

def main():
    x, y, z = (1, 0, 0)
    angle_x, angle_y, angle_z = (0.1, 0.2, 0.3)
    while True:
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
        print(f'({x:.2f}, {y:.2f}, {z:.2f})')
main()