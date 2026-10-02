import math

def transform_point(x, y, z, angle_x, angle_y, angle_z):
    rad_x, rad_y, rad_z = (math.radians(angle_x), math.radians(angle_y), math.radians(angle_z))
    cos_x, sin_x = (math.cos(rad_x), math.sin(rad_x))
    cos_y, sin_y = (math.cos(rad_y), math.sin(rad_y))
    cos_z, sin_z = (math.cos(rad_z), math.sin(rad_z))
    x1 = x
    y1 = y * cos_x - z * sin_x
    z1 = y * sin_x + z * cos_x
    x2 = x1 * cos_y + z1 * sin_y
    y2 = y1
    z2 = -x1 * sin_y + z1 * cos_y
    x3 = x2 * cos_z - y2 * sin_z
    y3 = x2 * sin_z + y2 * cos_z
    z3 = z2
    return (x3, y3, z3)

def rotate_forever():
    angle_x, angle_y, angle_z = (0, 0, 0)
    while True:
        x, y, z = (1, 1, 1)
        x, y, z = transform_point(x, y, z, angle_x, angle_y, angle_z)
        angle_x += 1
        angle_y += 2
        angle_z += 3
rotate_forever()