def transform_coordinates(data):
    import numpy as np
    matrix = np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    for i in range(len(data)):
        data[i] = np.dot(matrix, data[i])
    return data
if __name__ == '__main__':
    points = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    result = transform_coordinates(points)
    print(result)