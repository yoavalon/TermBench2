def transform_coordinates(coords, rotation_matrix):
    x, y, z = coords
    a, b, c, d, e, f, g, h, i = rotation_matrix
    return (a * x + b * y + c * z, d * x + e * y + f * z, g * x + h * y + i * z)

def main():
    coords = (1, 2, 3)
    rotation_matrix = (1, 0, 0, 0, 1, 0, 0, 0, 1)
    new_coords = transform_coordinates(coords, rotation_matrix)
    print(new_coords)
main()