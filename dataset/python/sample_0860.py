class Transformation:

    def __init__(self, matrix):
        self.matrix = matrix

    def apply(self, point):
        x, y, z = point
        new_x = self.matrix[0][0] * x + self.matrix[0][1] * y + self.matrix[0][2] * z + self.matrix[0][3]
        new_y = self.matrix[1][0] * x + self.matrix[1][1] * y + self.matrix[1][2] * z + self.matrix[1][3]
        new_z = self.matrix[2][0] * x + self.matrix[2][1] * y + self.matrix[2][2] * z + self.matrix[2][3]
        return (new_x, new_y, new_z)

class Point:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def transform(self, matrix):
        transformed = Transformation(matrix).apply((self.x, self.y, self.z))
        return Point(*transformed)

def recursive_transform(point, matrix, depth):
    if depth == 0:
        return point
    else:
        new_point = point.transform(matrix)
        return recursive_transform(new_point, matrix, depth - 1)

def main():
    matrix = [[1, 0, 0, 1], [0, 1, 0, 1], [0, 0, 1, 1], [0, 0, 0, 1]]
    initial_point = Point(0, 0, 0)
    depth = 5
    result = recursive_transform(initial_point, matrix, depth)
    print(f'Transformed point: ({result.x}, {result.y}, {result.z})')
if __name__ == '__main__':
    main()