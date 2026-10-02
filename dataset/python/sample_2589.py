import numpy as np

def transform_point(matrix, point):
    return np.dot(matrix, point)

def generate_rotation_matrix(angle, axis):
    c, s = (np.cos(angle), np.sin(angle))
    if axis == 'x':
        return np.array([[1, 0, 0], [0, c, -s], [0, s, c]])
    elif axis == 'y':
        return np.array([[c, 0, s], [0, 1, 0], [-s, 0, c]])
    elif axis == 'z':
        return np.array([[c, -s, 0], [s, c, 0], [0, 0, 1]])

def main():
    point = np.array([1, 2, 3])
    angle = np.pi / 4
    matrix = generate_rotation_matrix(angle, 'z')
    transformed_point = transform_point(matrix, point)
    print(transformed_point)
main()