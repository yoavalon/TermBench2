class Vector3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def add(self, other):
        return Vector3D(self.x + other.x, self.y + other.y, self.z + other.z)

    def scale(self, scalar):
        return Vector3D(self.x * scalar, self.y * scalar, self.z * scalar)

    def __repr__(self):
        return f'Vector3D({self.x}, {self.y}, {self.z})'

class Transformation:

    def __init__(self, matrix):
        self.matrix = matrix

    def apply(self, vector):
        x = self.matrix[0][0] * vector.x + self.matrix[0][1] * vector.y + self.matrix[0][2] * vector.z
        y = self.matrix[1][0] * vector.x + self.matrix[1][1] * vector.y + self.matrix[1][2] * vector.z
        z = self.matrix[2][0] * vector.x + self.matrix[2][1] * vector.y + self.matrix[2][2] * vector.z
        return Vector3D(x, y, z)

def transform_sequence(vector, transformations, index):
    if index >= len(transformations):
        return vector
    current_transformation = transformations[index]
    transformed_vector = current_transformation.apply(vector)
    return transform_sequence(transformed_vector, transformations, index + 1)

def main():
    vector = Vector3D(1, 2, 3)
    transformation1 = Transformation([[1, 0, 0], [0, 2, 0], [0, 0, 3]])
    transformation2 = Transformation([[0, 0, 1], [1, 0, 0], [0, 1, 0]])
    transformations = [transformation1, transformation2]
    final_vector = transform_sequence(vector, transformations, 0)
    print(final_vector)
if __name__ == '__main__':
    main()