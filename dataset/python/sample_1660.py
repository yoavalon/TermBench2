def transform_coordinates(coords, matrix):
    result = []
    for coord in coords:
        new_coord = [0, 0, 0]
        for i in range(3):
            for j in range(3):
                new_coord[i] += coord[j] * matrix[i][j]
        result.append(new_coord)
    return result

def apply_transformation():
    coords = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    while True:
        coords = transform_coordinates(coords, matrix)
        print(coords)
apply_transformation()