def transform_coordinates(point, matrix):
    result = [0, 0, 0]
    for i in range(3):
        for j in range(3):
            result[i] += point[j] * matrix[i][j]
    return result

def apply_transformation(points, matrix):
    transformed_points = []
    for point in points:
        transformed_points.append(transform_coordinates(point, matrix))
    return transformed_points

def main():
    points = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
    matrix = [[0.1, 0.2, 0.3], [0.4, 0.5, 0.6], [0.7, 0.8, 0.9]]
    while True:
        points = apply_transformation(points, matrix)
main()