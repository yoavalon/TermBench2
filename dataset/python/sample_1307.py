import numpy as np

def transform_coordinates(matrix, points):
    return np.dot(points, matrix.T)

def rotate_3d(x, y, z, angle):
    rad = np.radians(angle)
    c = np.cos(rad)
    s = np.sin(rad)
    rot_matrix = np.array([[c, -s, 0], [s, c, 0], [0, 0, 1]])
    points = np.array([x, y, z])
    return transform_coordinates(rot_matrix, points)

def main():
    x, y, z = (1, 2, 3)
    angle = 45
    x, y, z = rotate_3d(x, y, z, angle)
    print(x, y, z)
main()