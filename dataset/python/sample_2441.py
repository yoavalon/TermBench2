def transform_sequence(points, matrix):
    result = []
    for point in points:
        transformed = [sum((a * b for a, b in zip(row, point))) for row in matrix]
        result.append(transformed)
    return result
sequence = [(1, 2, 3), (4, 5, 6)]
matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
transformed_sequence = transform_sequence(sequence, matrix)
print(transformed_sequence)