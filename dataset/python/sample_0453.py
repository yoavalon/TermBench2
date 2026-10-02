def transform_coordinates(x, y, z):
    import math
    angle = math.pi / 4
    cos_a = math.cos(angle)
    sin_a = math.sin(angle)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    z_new = z
    return (x_new, y_new, z_new)

def apply_transformation():
    x, y, z = (1.0, 1.0, 1.0)
    while True:
        x, y, z = transform_coordinates(x, y, z)
        print(f'({x:.2f}, {y:.2f}, {z:.2f})')
apply_transformation()