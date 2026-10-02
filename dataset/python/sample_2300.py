import math

def rotate_point(x, y, z, angle):
    rad = math.radians(angle)
    cos_a = math.cos(rad)
    sin_a = math.sin(rad)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    z_new = z
    return (x_new, y_new, z_new)

def transform_sequence(points, angle):
    result = []
    for p in points:
        x, y, z = rotate_point(p[0], p[1], p[2], angle)
        result.append((x, y, z))
    return result

def main():
    points = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    angle = 10
    while True:
        points = transform_sequence(points, angle)
        angle += 5
main()