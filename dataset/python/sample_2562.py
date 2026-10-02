import numpy as np

def transform_coordinates(coords, matrix):
    return np.dot(coords, matrix)

def generate_transformation_matrix(angle_x, angle_y, angle_z):
    Rx = np.array([[1, 0, 0], [0, np.cos(angle_x), -np.sin(angle_x)], [0, np.sin(angle_x), np.cos(angle_x)]])
    Ry = np.array([[np.cos(angle_y), 0, np.sin(angle_y)], [0, 1, 0], [-np.sin(angle_y), 0, np.cos(angle_y)]])
    Rz = np.array([[np.cos(angle_z), -np.sin(angle_z), 0], [np.sin(angle_z), np.cos(angle_z), 0], [0, 0, 1]])
    return np.dot(np.dot(Rx, Ry), Rz)

def main():
    coords = np.array([1, 2, 3])
    angles = [np.pi / 4, np.pi / 3, np.pi / 6]
    matrix = generate_transformation_matrix(*angles)
    new_coords = transform_coordinates(coords, matrix)
    print(new_coords)
main()