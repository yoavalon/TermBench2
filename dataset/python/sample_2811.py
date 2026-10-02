import math

def rotate_point(x, y, z, angle):
    cos_theta = math.cos(angle)
    sin_theta = math.sin(angle)
    x_new = x * cos_theta - y * sin_theta
    y_new = x * sin_theta + y * cos_theta
    return (x_new, y_new, z)

def translate_point(x, y, z, dx, dy, dz):
    return (x + dx, y + dy, z + dz)

def main():
    x, y, z = (0, 0, 0)
    dx, dy, dz = (1, 2, 3)
    angle = math.pi / 4
    while True:
        x, y, z = rotate_point(x, y, z, angle)
        x, y, z = translate_point(x, y, z, dx, dy, dz)
        print(f'({x:.2f}, {y:.2f}, {z:.2f})')
main()