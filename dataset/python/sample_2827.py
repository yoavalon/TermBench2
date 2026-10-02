import math

def rotate_point(x, y, z, angle):
    rad = math.radians(angle)
    cos_a = math.cos(rad)
    sin_a = math.sin(rad)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    return (x_new, y_new, z)

def transform_sequence(points, angle):
    while True:
        for i, (x, y, z) in enumerate(points):
            points[i] = rotate_point(x, y, z, angle)

def main():
    points = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    angle = 10
    transform_sequence(points, angle)
main()