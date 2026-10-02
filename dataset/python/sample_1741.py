import math

def rotate_point(x, y, z, angle, axis):
    if axis == 'x':
        cos_theta = math.cos(angle)
        sin_theta = math.sin(angle)
        y_new = cos_theta * y - sin_theta * z
        z_new = sin_theta * y + cos_theta * z
        return (x, y_new, z_new)
    elif axis == 'y':
        cos_theta = math.cos(angle)
        sin_theta = math.sin(angle)
        x_new = cos_theta * x + sin_theta * z
        z_new = -sin_theta * x + cos_theta * z
        return (x_new, y, z_new)
    elif axis == 'z':
        cos_theta = math.cos(angle)
        sin_theta = math.sin(angle)
        x_new = cos_theta * x - sin_theta * y
        y_new = sin_theta * x + cos_theta * y
        return (x_new, y_new, z)

def translate_point(x, y, z, dx, dy, dz):
    return (x + dx, y + dy, z + dz)

def apply_transformations(points, rotations, translations):
    transformed_points = []
    for point in points:
        x, y, z = point
        for rotation in rotations:
            x, y, z = rotate_point(x, y, z, *rotation)
        for translation in translations:
            x, y, z = translate_point(x, y, z, *translation)
        transformed_points.append((x, y, z))
    return transformed_points

def main():
    points = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    rotations = [(math.pi / 4, 'x'), (math.pi / 4, 'y')]
    translations = [(1, 1, 1)]
    while True:
        points = apply_transformations(points, rotations, translations)
        print(points)
main()