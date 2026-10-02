import numpy as np

def transform_3d_coordinates(data, matrix):
    transformed_data = np.dot(data, matrix)
    return transformed_data

def main():
    data = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    matrix = np.array([[0, 1, 0], [0, 0, 1], [1, 0, 0]])
    result = transform_3d_coordinates(data, matrix)
    print(result)

if __name__ == '__main__':
    main()