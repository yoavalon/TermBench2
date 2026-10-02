import numpy as np

def transform_coordinates(points, matrix):
    return np.dot(points, matrix.T)

def main():
    points = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    matrix = np.array([[0, 1, 0], [0, 0, 1], [1, 0, 0]])
    transformed = transform_coordinates(points, matrix)
    print(transformed)
main()