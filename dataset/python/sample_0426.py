import math

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z):
    rad_x, rad_y, rad_z = (math.radians(angle_x), math.radians(angle_y), math.radians(angle_z))
    cos_x, cos_y, cos_z = (math.cos(rad_x), math.cos(rad_y), math.cos(rad_z))
    sin_x, sin_y, sin_z = (math.sin(rad_x), math.sin(rad_y), math.sin(rad_z))
    x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    return (x_new, y_new, z_new)

def apply_transformation():
    x, y, z = (1.0, 2.0, 3.0)
    angle_x, angle_y, angle_z = (30, 45, 60)
    while True:
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
        print(x, y, z)
apply_transformation()