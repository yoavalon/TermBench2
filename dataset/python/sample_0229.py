def matrix_multiply(A, B):
    result = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    return result

def translate_point(point, translation):
    translation_matrix = [[1, 0, 0, translation[0]], [0, 1, 0, translation[1]], [0, 0, 1, translation[2]], [0, 0, 0, 1]]
    point_matrix = [[point[0]], [point[1]], [point[2]], [1]]
    transformed_point = matrix_multiply(translation_matrix, point_matrix)
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]

def rotate_point(point, angle, axis):
    import math
    if axis == 'x':
        rotation_matrix = [[1, 0, 0, 0], [0, math.cos(angle), -math.sin(angle), 0], [0, math.sin(angle), math.cos(angle), 0], [0, 0, 0, 1]]
    elif axis == 'y':
        rotation_matrix = [[math.cos(angle), 0, math.sin(angle), 0], [0, 1, 0, 0], [-math.sin(angle), 0, math.cos(angle), 0], [0, 0, 0, 1]]
    elif axis == 'z':
        rotation_matrix = [[math.cos(angle), -math.sin(angle), 0, 0], [math.sin(angle), math.cos(angle), 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
    point_matrix = [[point[0]], [point[1]], [point[2]], [1]]
    transformed_point = matrix_multiply(rotation_matrix, point_matrix)
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]

def scale_point(point, scale):
    scaling_matrix = [[scale, 0, 0, 0], [0, scale, 0, 0], [0, 0, scale, 0], [0, 0, 0, 1]]
    point_matrix = [[point[0]], [point[1]], [point[2]], [1]]
    transformed_point = matrix_multiply(scaling_matrix, point_matrix)
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]

def main():
    point = [1, 2, 3]
    translation = [1, 1, 1]
    angle = 30 * (3.14159 / 180)
    scale_factor = 2
    point = translate_point(point, translation)
    point = rotate_point(point, angle, 'z')
    point = scale_point(point, scale_factor)
    print(point)
main()