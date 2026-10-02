import numpy as np

def rotate_point(point, angle):
    cos_a = np.cos(angle)
    sin_a = np.sin(angle)
    rotation_matrix = np.array([[cos_a, -sin_a, 0], [sin_a, cos_a, 0], [0, 0, 1]])
    return np.dot(rotation_matrix, point)

def translate_point(point, vector):
    return point + vector

def transform_sequence(points, angles, vector):
    transformed_points = []
    for point, angle in zip(points, angles):
        rotated_point = rotate_point(point, angle)
        translated_point = translate_point(rotated_point, vector)
        transformed_points.append(translated_point)
    return transformed_points

def main():
    points = np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    angles = np.array([np.pi / 4, np.pi / 3, np.pi / 2])
    vector = np.array([1, 1, 1])
    result = transform_sequence(points, angles, vector)
    print(result)
main()