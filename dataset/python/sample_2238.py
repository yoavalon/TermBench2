import math

def transform_point(x, y, z, angle_x, angle_y, angle_z):
    cos_x, sin_x = (math.cos(angle_x), math.sin(angle_x))
    cos_y, sin_y = (math.cos(angle_y), math.sin(angle_y))
    cos_z, sin_z = (math.cos(angle_z), math.sin(angle_z))
    x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    return (x_new, y_new, z_new)

def rotate_around_axis():
    x, y, z = (1.0, 2.0, 3.0)
    angle_x, angle_y, angle_z = (math.pi / 4, math.pi / 4, math.pi / 4)
    while True:
        x, y, z = transform_point(x, y, z, angle_x, angle_y, angle_z)
        print(f'Coordinates: ({x:.6f}, {y:.6f}, {z:.6f})')

def main():
    rotate_around_axis()
main()