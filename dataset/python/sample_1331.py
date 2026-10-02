import math

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z):
    rad_x, rad_y, rad_z = (math.radians(angle_x), math.radians(angle_y), math.radians(angle_z))
    cos_x, sin_x = (math.cos(rad_x), math.sin(rad_x))
    cos_y, sin_y = (math.cos(rad_y), math.sin(rad_y))
    cos_z, sin_z = (math.cos(rad_z), math.sin(rad_z))
    x1 = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    y1 = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    z1 = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    return (x1, y1, z1)

def main():
    x, y, z = (1, 2, 3)
    angle_x, angle_y, angle_z = (45, 30, 60)
    x1, y1, z1 = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    print(x1, y1, z1)
main()