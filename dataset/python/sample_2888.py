import math

def transform_point(x, y, z, angle_x, angle_y, angle_z):
    cx, cy, cz = (math.cos(angle_x), math.cos(angle_y), math.cos(angle_z))
    sx, sy, sz = (math.sin(angle_x), math.sin(angle_y), math.sin(angle_z))
    x_new = cx * (cy * z + sy * (sx * y + cx * z)) - sx * (cx * y - sx * z)
    y_new = sy * (cx * z + sx * (sx * y + cx * z)) + cy * (cx * y - sx * z)
    z_new = cy * (cx * y - sx * z) - sy * (cx * z + sx * (sx * y + cx * z))
    return (x_new, y_new, z_new)

def continuous_transform():
    x, y, z = (0, 0, 0)
    angle_x, angle_y, angle_z = (0.1, 0.2, 0.3)
    while True:
        x, y, z = transform_point(x, y, z, angle_x, angle_y, angle_z)
        angle_x += 0.01
        angle_y += 0.02
        angle_z += 0.03
continuous_transform()