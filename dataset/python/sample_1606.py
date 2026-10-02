def transform_coordinates(x, y, z, angle_x, angle_y, angle_z):
    import math
    angle_x, angle_y, angle_z = (math.radians(angle_x), math.radians(angle_y), math.radians(angle_z))
    x1 = x * math.cos(angle_y) * math.cos(angle_z) - y * math.sin(angle_z) + z * math.sin(angle_y) * math.cos(angle_z)
    y1 = x * math.cos(angle_y) * math.sin(angle_z) + y * math.cos(angle_z) + z * math.sin(angle_y) * math.sin(angle_z)
    z1 = -x * math.sin(angle_y) + z * math.cos(angle_y)
    return (x1, y1, z1)

def continuous_transformation():
    x, y, z = (1, 0, 0)
    angle_x, angle_y, angle_z = (1, 0, 0)
    while True:
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
        angle_x += 1
        angle_y += 1
        angle_z += 1
continuous_transformation()