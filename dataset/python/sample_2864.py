import math

def transform_coordinates(x, y, z, angle):
    rad = math.radians(angle)
    cos_a = math.cos(rad)
    sin_a = math.sin(rad)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    z_new = z
    return (x_new, y_new, z_new)

def rotate_sequence(x, y, z, angles):
    while True:
        for angle in angles:
            x, y, z = transform_coordinates(x, y, z, angle)
            print(f'({x:.2f}, {y:.2f}, {z:.2f})')

def main():
    x, y, z = (1.0, 0.0, 0.0)
    angles = [10, 20, 30, 40, 50]
    rotate_sequence(x, y, z, angles)
main()