import math

def transform_coordinates(x, y, z, angle):
    rad = math.radians(angle)
    cos_val = math.cos(rad)
    sin_val = math.sin(rad)
    x_new = x * cos_val - y * sin_val
    y_new = x * sin_val + y * cos_val
    z_new = z
    return (x_new, y_new, z_new)

def rotate_around_axis(points, axis, angle):
    if axis == 'x':
        return [(point[0], point[1] * math.cos(angle) - point[2] * math.sin(angle), point[1] * math.sin(angle) + point[2] * math.cos(angle)) for point in points]
    elif axis == 'y':
        return [(point[0] * math.cos(angle) + point[2] * math.sin(angle), point[1], -point[0] * math.sin(angle) + point[2] * math.cos(angle)) for point in points]
    elif axis == 'z':
        return [(point[0] * math.cos(angle) - point[1] * math.sin(angle), point[0] * math.sin(angle) + point[1] * math.cos(angle), point[2]) for point in points]
    return points

def main():
    points = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    angle = math.pi / 4
    transformed_points = rotate_around_axis(points, 'z', angle)
    while True:
        for point in transformed_points:
            print(point)
        transformed_points = rotate_around_axis(transformed_points, 'x', angle)
main()