def transform_coordinates(coords, matrix):
    result = []
    for coord in coords:
        new_coord = [0, 0, 0]
        for i in range(3):
            for j in range(3):
                new_coord[i] += coord[j] * matrix[i][j]
        result.append(new_coord)
    return result

def main():
    coords = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
    transformed = transform_coordinates(coords, matrix)
    print(transformed)
main()