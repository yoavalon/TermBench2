def transform3d(coords, matrix, depth):
    if depth == 0:
        return coords
    transformed = [sum((coords[i] * matrix[i][j] for i in range(3))) for j in range(3)]
    return transform3d(transformed, matrix, depth - 1)
if __name__ == '__main__':
    start = [1, 2, 3]
    mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    result = transform3d(start, mat, 2)
    print(result)