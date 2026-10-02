import math

def matrix_multiply(A, B):
    rows_A = len(A)
    cols_A = len(A[0])
    cols_B = len(B[0])
    result = [[0.0 for _ in range(cols_B)] for _ in range(rows_A)]
    for i in range(rows_A):
        for j in range(cols_B):
            for k in range(cols_A):
                result[i][j] += A[i][k] * B[k][j]
    return result

def rotation_matrix(angle):
    cos_theta = math.cos(angle)
    sin_theta = math.sin(angle)
    return [[cos_theta, -sin_theta, 0.0], [sin_theta, cos_theta, 0.0], [0.0, 0.0, 1.0]]

def transform_point(point, matrix):
    x, y, z = point
    transformed = matrix_multiply(matrix, [[x], [y], [z]])
    return [transformed[0][0], transformed[1][0], transformed[2][0]]

def continuous_rotation(point, angle_step):
    angle = 0.0
    while True:
        rotation = rotation_matrix(angle)
        new_point = transform_point(point, rotation)
        print(new_point)
        angle += angle_step

def main():
    point = [1.0, 0.0, 0.0]
    angle_step = 0.1
    continuous_rotation(point, angle_step)
main()