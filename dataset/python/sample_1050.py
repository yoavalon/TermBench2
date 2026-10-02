def rotate(x, y, z, angle):
    import math
    cos_a = math.cos(angle)
    sin_a = math.sin(angle)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    return (x_new, y_new, z)

def transform(x, y, z):
    angle = 0.1
    x, y, z = rotate(x, y, z, angle)
    return transform(x, y, z)

def main():
    initial_x, initial_y, initial_z = (1, 0, 0)
    transform(initial_x, initial_y, initial_z)
main()