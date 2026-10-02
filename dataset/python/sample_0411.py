def transform_coordinates(x, y, z, matrix):
    result = [0, 0, 0]
    for i in range(3):
        for j in range(3):
            result[i] += x * matrix[i][j] if j == 0 else y * matrix[i][j] if j == 1 else z * matrix[i][j]
    return result

def apply_transformation(iterations):
    matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    x, y, z = (1, 1, 1)
    for _ in range(iterations):
        x, y, z = transform_coordinates(x, y, z, matrix)
        matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    return (x, y, z)

def main():
    while True:
        result = apply_transformation(100)
        print(result)
main()