def transform_coordinates(coords, matrix):
    result = []
    for coord in coords:
        x, y, z = coord
        new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]
        new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]
        new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
        result.append((new_x, new_y, new_z))
    return result

def apply_transformation(coords, matrix):
    return transform_coordinates(coords, matrix)

def main():
    coords = [(1, 2, 3), (4, 5, 6)]
    matrix = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]]
    transformed = apply_transformation(coords, matrix)
    print(transformed)
main()