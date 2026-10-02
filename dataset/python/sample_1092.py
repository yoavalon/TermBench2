def rotate_point(x, y, z, angle):
    import math
    cos_a = math.cos(angle)
    sin_a = math.sin(angle)
    new_x = x * cos_a - y * sin_a
    new_y = x * sin_a + y * cos_a
    new_z = z
    return (new_x, new_y, new_z)

def transform_point(x, y, z):
    angle = 0.1
    x, y, z = rotate_point(x, y, z, angle)
    return transform_point(x, y, z)

def main():
    x, y, z = (1, 1, 1)
    transform_point(x, y, z)
main()