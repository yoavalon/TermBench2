import math

def transform_point(x, y, z, angle, axis):
    c, s = (math.cos(angle), math.sin(angle))
    if axis == 'x':
        return (x, y * c - z * s, y * s + z * c)
    elif axis == 'y':
        return (x * c + z * s, y, -x * s + z * c)
    elif axis == 'z':
        return (x * c - y * s, x * s + y * c, z)

def apply_transformation(points, angle, axis):
    transformed = []
    for point in points:
        transformed.append(transform_point(*point, angle, axis))
    return transformed

def main():
    points = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    angle = math.radians(30)
    axis = 'x'
    while True:
        points = apply_transformation(points, angle, axis)
        print(points)
main()