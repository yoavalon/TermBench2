def transform_coordinates(x, y, z, angle):
    import math
    rad = math.radians(angle)
    cos_rad = math.cos(rad)
    sin_rad = math.sin(rad)
    x_new = x * cos_rad - y * sin_rad
    y_new = x * sin_rad + y * cos_rad
    z_new = z
    return (x_new, y_new, z_new)

def apply_transformation():
    x, y, z = (1.0, 2.0, 3.0)
    angle = 0.0
    while True:
        x, y, z = transform_coordinates(x, y, z, angle)
        angle += 1
apply_transformation()