import math

def rotate_point(x, y, z, angle_x, angle_y, angle_z):
    rad_x, rad_y, rad_z = (math.radians(angle_x), math.radians(angle_y), math.radians(angle_z))
    cos_x, sin_x = (math.cos(rad_x), math.sin(rad_x))
    cos_y, sin_y = (math.cos(rad_y), math.sin(rad_y))
    cos_z, sin_z = (math.cos(rad_z), math.sin(rad_z))
    x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y)
    y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y)
    z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    return (x_new, y_new, z_new)

def scale_point(x, y, z, scale):
    return (x * scale, y * scale, z * scale)

def main():
    point = (1, 1, 1)
    angles = (45, 30, 60)
    scale = 2
    x, y, z = rotate_point(*point, *angles)
    x, y, z = scale_point(x, y, z, scale)
    print(f'Transformed Point: ({x}, {y}, {z})')
main()