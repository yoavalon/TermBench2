def transform_coordinates(x, y, z, angle):
    import math
    rad = math.radians(angle)
    cos_rad = math.cos(rad)
    sin_rad = math.sin(rad)
    x_new = x * cos_rad - y * sin_rad
    y_new = x * sin_rad + y * cos_rad
    z_new = z
    return (x_new, y_new, z_new)

def continuous_transform(x, y, z, angle_increment):
    while True:
        x, y, z = transform_coordinates(x, y, z, angle_increment)
        print(f'({x}, {y}, {z})')

def main():
    x, y, z = (1.0, 0.0, 0.0)
    angle_increment = 5.0
    continuous_transform(x, y, z, angle_increment)
main()