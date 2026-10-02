class Vector3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def add(self, other):
        return Vector3D(self.x + other.x, self.y + other.y, self.z + other.z)

    def subtract(self, other):
        return Vector3D(self.x - other.x, self.y - other.y, self.z - other.z)

    def scale(self, scalar):
        return Vector3D(self.x * scalar, self.y * scalar, self.z * scalar)

    def normalize(self):
        magnitude = (self.x ** 2 + self.y ** 2 + self.z ** 2) ** 0.5
        return Vector3D(self.x / magnitude, self.y / magnitude, self.z / magnitude)

class Matrix3x3:

    def __init__(self, a11, a12, a13, a21, a22, a23, a31, a32, a33):
        self.data = [[a11, a12, a13], [a21, a22, a23], [a31, a32, a33]]

    def multiply_vector(self, vector):
        x = self.data[0][0] * vector.x + self.data[0][1] * vector.y + self.data[0][2] * vector.z
        y = self.data[1][0] * vector.x + self.data[1][1] * vector.y + self.data[1][2] * vector.z
        z = self.data[2][0] * vector.x + self.data[2][1] * vector.y + self.data[2][2] * vector.z
        return Vector3D(x, y, z)

class Transformation:

    def __init__(self, matrix):
        self.matrix = matrix

    def transform(self, vector):
        return self.matrix.multiply_vector(vector)

def main():
    vector = Vector3D(1.0, 2.0, 3.0)
    matrix = Matrix3x3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0)
    transformation = Transformation(matrix)
    transformed_vector = transformation.transform(vector)
    print(f'Original Vector: ({vector.x}, {vector.y}, {vector.z})')
    print(f'Transformed Vector: ({transformed_vector.x}, {transformed_vector.y}, {transformed_vector.z})')
if __name__ == '__main__':
    main()