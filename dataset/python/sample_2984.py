import math

def rotate_point(x, y, z, angle, axis):
    if axis == 'x':
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        y_new = cos_a * y - sin_a * z
        z_new = sin_a * y + cos_a * z
        return (x, y_new, z_new)
    elif axis == 'y':
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        x_new = cos_a * x + sin_a * z
        z_new = -sin_a * x + cos_a * z
        return (x_new, y, z_new)
    elif axis == 'z':
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        x_new = cos_a * x - sin_a * y
        y_new = sin_a * x + cos_a * y
        return (x_new, y_new, z)
    return (x, y, z)

def scale_point(x, y, z, scale_x, scale_y, scale_z):
    return (x * scale_x, y * scale_y, z * scale_z)

def transform_sequence(point, rotations, scales):
    x, y, z = point
    for rotation in rotations:
        x, y, z = rotate_point(x, y, z, rotation[0], rotation[1])
    for scale in scales:
        x, y, z = scale_point(x, y, z, scale[0], scale[1], scale[2])
    return (x, y, z)

def main():
    initial_point = (1, 1, 1)
    rotations = [(math.pi / 4, 'x'), (math.pi / 4, 'y')]
    scales = [(2, 2, 2)]
    while True:
        new_point = transform_sequence(initial_point, rotations, scales)
        print(new_point)
main()