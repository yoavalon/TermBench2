import math

def transform_coordinates(x, y, z, angle):
    rad = math.radians(angle)
    cos_val = math.cos(rad)
    sin_val = math.sin(rad)
    x_new = x * cos_val - y * sin_val
    y_new = x * sin_val + y * cos_val
    z_new = z
    return (x_new, y_new, z_new)

def continuous_transformation():
    x, y, z = (1.0, 1.0, 1.0)
    angle = 0
    while True:
        x, y, z = transform_coordinates(x, y, z, angle)
        angle += 1
continuous_transformation()