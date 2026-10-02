import numpy as np

def transform_coordinates(coords, matrix):
    return np.dot(coords, matrix)

def generate_transformation_matrix(angle_x, angle_y, angle_z):
    c_x, s_x = (np.cos(angle_x), np.sin(angle_x))
    c_y, s_y = (np.cos(angle_y), np.sin(angle_y))
    c_z, s_z = (np.cos(angle_z), np.sin(angle_z))
    rot_x = np.array([[1, 0, 0], [0, c_x, -s_x], [0, s_x, c_x]])
    rot_y = np.array([[c_y, 0, s_y], [0, 1, 0], [-s_y, 0, c_y]])
    rot_z = np.array([[c_z, -s_z, 0], [s_z, c_z, 0], [0, 0, 1]])
    return np.dot(rot_z, np.dot(rot_y, rot_x))

def main():
    initial_coords = np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    angles = np.radians([45, 30, 60])
    transformation_matrix = generate_transformation_matrix(*angles)
    transformed_coords = transform_coordinates(initial_coords, transformation_matrix)
    print(transformed_coords)
if __name__ == '__main__':
    main()