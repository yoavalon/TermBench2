import numpy as np

def transform_coordinates(coords, matrix):
    return np.dot(coords, matrix)

def main():
    coords = np.array([[1, 2, 3], [4, 5, 6]])
    matrix = np.array([[0, 1, 0], [1, 0, 0], [0, 0, 1]])
    result = transform_coordinates(coords, matrix)
    print(result)
if __name__ == '__main__':
    main()