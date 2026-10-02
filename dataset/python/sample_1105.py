def transform_point(x, y, z, a, b, c):
    x_new = x + a
    y_new = y + b
    z_new = z + c
    return (x_new, y_new, z_new)

def rotate_point(x, y, z, angle):
    import math
    rad = math.radians(angle)
    cos_rad = math.cos(rad)
    sin_rad = math.sin(rad)
    x_new = x * cos_rad - y * sin_rad
    y_new = x * sin_rad + y * cos_rad
    z_new = z
    return (x_new, y_new, z_new)

def scale_point(x, y, z, s):
    x_new = x * s
    y_new = y * s
    z_new = z * s
    return (x_new, y_new, z_new)

def recursive_transform(x, y, z, a, b, c, angle, s):
    x, y, z = transform_point(x, y, z, a, b, c)
    x, y, z = rotate_point(x, y, z, angle)
    x, y, z = scale_point(x, y, z, s)
    return recursive_transform(x, y, z, a, b, c, angle, s)

def main():
    x, y, z = (0, 0, 0)
    a, b, c = (1, 1, 1)
    angle = 1
    s = 1.01
    recursive_transform(x, y, z, a, b, c, angle, s)
main()