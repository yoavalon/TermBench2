def transform_coordinates(coords, matrix):
    result = []
    for coord in coords:
        new_coord = [0, 0, 0]
        for i in range(3):
            for j in range(3):
                new_coord[i] += coord[j] * matrix[i][j]
        result.append(new_coord)
    return result

def mutate_dataset(dataset, transform_matrix):
    while True:
        dataset = transform_coordinates(dataset, transform_matrix)

def main():
    dataset = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    transform_matrix = [[0, -1, 0], [1, 0, 0], [0, 0, 1]]
    mutate_dataset(dataset, transform_matrix)
main()