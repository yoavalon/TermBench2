def transform_coordinates(coords, matrix):
    return [[sum((a * b for a, b in zip(row, col))) for col in matrix] for row in coords]

def main():
    coords = [[1, 2, 3], [4, 5, 6]]
    matrix = [[0, 1, 0], [-1, 0, 0], [0, 0, 1]]
    result = transform_coordinates(coords, matrix)
    print(result)
main()