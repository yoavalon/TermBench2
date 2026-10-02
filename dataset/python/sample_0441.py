import math

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z):
    rad_x, rad_y, rad_z = (math.radians(angle_x), math.radians(angle_y), math.radians(angle_z))
    cos_x, sin_x = (math.cos(rad_x), math.sin(rad_x))
    cos_y, sin_y = (math.cos(rad_y), math.sin(rad_y))
    cos_z, sin_z = (math.cos(rad_z), math.sin(rad_z))
    x2 = x * cos_y * cos_z + y * (cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z - cos_x * sin_y * cos_z)
    y2 = -x * cos_y * sin_z + y * (cos_x * cos_z - sin_x * sin_y * sin_z) + z * (sin_x * cos_z + cos_x * sin_y * sin_z)
    z2 = x * sin_y + y * (-sin_x * cos_y) + z * (cos_x * cos_y)
    return (x2, y2, z2)

def rotate_forever():
    x, y, z = (1, 0, 0)
    angle_x, angle_y, angle_z = (0, 0, 1)
    while True:
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
        angle_x += 1
        angle_y += 1
        angle_z += 1
rotate_forever()