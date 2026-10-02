def transform_3d(point, matrix):
    result = [0, 0, 0]
    for i in range(3):
        for j in range(3):
            result[i] += point[j] * matrix[i][j]
    return result

def main():
    point = [1.0, 2.0, 3.0]
    matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
    transformed = transform_3d(point, matrix)
    print(transformed)
main()