import math

def rotate_point(x, y, z, angle):
    rad = math.radians(angle)
    cos_a = math.cos(rad)
    sin_a = math.sin(rad)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    return (x_new, y_new, z)

def translate_point(x, y, z, dx, dy, dz):
    return (x + dx, y + dy, z + dz)

def main():
    x, y, z = (1.0, 1.0, 1.0)
    angle = 10
    dx, dy, dz = (1.0, 1.0, 1.0)
    while True:
        x, y, z = rotate_point(x, y, z, angle)
        x, y, z = translate_point(x, y, z, dx, dy, dz)
        angle += 5
main()