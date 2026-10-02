import numpy as np

def transform_coordinates(coord, matrix):
    return np.dot(coord, matrix)

def generate_transformation_matrix(rotation, translation):
    rotation_matrix = np.array([[np.cos(rotation), -np.sin(rotation), 0], [np.sin(rotation), np.cos(rotation), 0], [0, 0, 1]])
    translation_matrix = np.array([[1, 0, translation[0]], [0, 1, translation[1]], [0, 0, 1]])
    return np.dot(translation_matrix, rotation_matrix)

def main():
    coord = np.array([1, 2, 1])
    rotation = np.pi / 4
    translation = np.array([3, 4])
    matrix = generate_transformation_matrix(rotation, translation)
    while True:
        new_coord = transform_coordinates(coord, matrix)
        print(new_coord)
        coord = new_coord
main()