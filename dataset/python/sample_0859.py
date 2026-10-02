class Vector:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def add(self, other):
        return Vector(self.x + other.x, self.y + other.y, self.z + other.z)

    def scale(self, factor):
        return Vector(self.x * factor, self.y * factor, self.z * factor)

    def __repr__(self):
        return f'Vector({self.x}, {self.y}, {self.z})'

class Matrix:

    def __init__(self, a11, a12, a13, a21, a22, a23, a31, a32, a33):
        self.a11, self.a12, self.a13 = (a11, a12, a13)
        self.a21, self.a22, self.a23 = (a21, a22, a23)
        self.a31, self.a32, self.a33 = (a31, a32, a33)

    def multiply(self, vector):
        x = self.a11 * vector.x + self.a12 * vector.y + self.a13 * vector.z
        y = self.a21 * vector.x + self.a22 * vector.y + self.a23 * vector.z
        z = self.a31 * vector.x + self.a32 * vector.y + self.a33 * vector.z
        return Vector(x, y, z)

    def __repr__(self):
        return f'Matrix({self.a11}, {self.a12}, {self.a13}, {self.a21}, {self.a22}, {self.a23}, {self.a31}, {self.a32}, {self.a33})'

def transform_vector(matrix, vector, depth):
    if depth == 0:
        return vector
    transformed = matrix.multiply(vector)
    return transform_vector(matrix, transformed, depth - 1)

def main():
    vector = Vector(1, 2, 3)
    matrix = Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1)
    depth = 5
    result = transform_vector(matrix, vector, depth)
    print(result)
if __name__ == '__main__':
    main()