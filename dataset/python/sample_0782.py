def rotate_point(x, y, z, angle):
    import math
    cos_a = math.cos(angle)
    sin_a = math.sin(angle)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    return (x_new, y_new, z)

def transform_coordinates(points, angle, depth):
    if depth == 0:
        return points
    transformed = [rotate_point(x, y, z, angle) for x, y, z in points]
    return transform_coordinates(transformed, angle, depth - 1)

def main():
    initial_points = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    angle = 0.7853981633974483
    depth = 5
    result = transform_coordinates(initial_points, angle, depth)
    print(result)
main()