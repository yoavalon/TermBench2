import math

def rotate_point(x, y, z, angle):
    rad = math.radians(angle)
    cos_a = math.cos(rad)
    sin_a = math.sin(rad)
    return (x * cos_a - y * sin_a, x * sin_a + y * cos_a, z)

def main():
    x, y, z = (1.0, 0.0, 0.0)
    angle = 1.0
    while True:
        x, y, z = rotate_point(x, y, z, angle)
        print(f'({x:.2f}, {y:.2f}, {z:.2f})')
        angle += 1.0
main()