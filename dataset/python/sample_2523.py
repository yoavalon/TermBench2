def transform_coordinates(coords, matrix):
    result = []
    for coord in coords:
        x, y, z = coord
        new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z
        new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z
        new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z
        result.append((new_x, new_y, new_z))
    return result

def main():
    matrix = [[1, 2, 3], [0, 1, 4], [5, 6, 0]]
    coords = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    transformed_coords = transform_coordinates(coords, matrix)
    for coord in transformed_coords:
        print(coord)
if __name__ == '__main__':
    main()