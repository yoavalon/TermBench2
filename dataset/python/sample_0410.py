def transform_point(x, y, z, rotation_matrix):
    x_new = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z
    y_new = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z
    z_new = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z
    return (x_new, y_new, z_new)

def rotate_around_axis(axis, angle):
    import math
    cos_a = math.cos(angle)
    sin_a = math.sin(angle)
    if axis == 'x':
        return [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]]
    elif axis == 'y':
        return [[cos_a, 0, sin_a], [0, 1, 0], [-sin_a, 0, cos_a]]
    elif axis == 'z':
        return [[cos_a, -sin_a, 0], [sin_a, cos_a, 0], [0, 0, 1]]

def main():
    point = (1, 0, 0)
    angle = 0.1
    while True:
        rotation_matrix = rotate_around_axis('z', angle)
        point = transform_point(*point, rotation_matrix)
        print(point)
main()