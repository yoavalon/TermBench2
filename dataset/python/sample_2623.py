class Matrix:

    def __init__(self, data):
        self.data = data
        self.rows = len(data)
        self.cols = len(data[0]) if self.rows > 0 else 0

    def __mul__(self, other):
        result = [[0 for _ in range(other.cols)] for _ in range(self.rows)]
        for i in range(self.rows):
            for j in range(other.cols):
                for k in range(other.rows):
                    result[i][j] += self.data[i][k] * other.data[k][j]
        return Matrix(result)

    def __repr__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.data])

def rotation_matrix(axis, theta):
    if axis == 'x':
        return Matrix([[1, 0, 0], [0, cos(theta), -sin(theta)], [0, sin(theta), cos(theta)]])
    elif axis == 'y':
        return Matrix([[cos(theta), 0, sin(theta)], [0, 1, 0], [-sin(theta), 0, cos(theta)]])
    elif axis == 'z':
        return Matrix([[cos(theta), -sin(theta), 0], [sin(theta), cos(theta), 0], [0, 0, 1]])

def transform_point(matrix, point):
    point_matrix = Matrix([[point[0]], [point[1]], [point[2]]])
    transformed = matrix * point_matrix
    return [transformed.data[0][0], transformed.data[1][0], transformed.data[2][0]]

def main():
    point = [1, 2, 3]
    theta = 0.785398
    matrix_x = rotation_matrix('x', theta)
    matrix_y = rotation_matrix('y', theta)
    matrix_z = rotation_matrix('z', theta)
    transformed_x = transform_point(matrix_x, point)
    transformed_y = transform_point(matrix_y, point)
    transformed_z = transform_point(matrix_z, point)
    print('Transformed by X-axis:', transformed_x)
    print('Transformed by Y-axis:', transformed_y)
    print('Transformed by Z-axis:', transformed_z)
if __name__ == '__main__':
    main()