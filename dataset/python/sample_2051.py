class Vector:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def add(self, other):
        return Vector(self.x + other.x, self.y + other.y, self.z + other.z)

    def scale(self, scalar):
        return Vector(self.x * scalar, self.y * scalar, self.z * scalar)

    def __repr__(self):
        return f'Vector({self.x}, {self.y}, {self.z})'

class Transformation:

    def __init__(self, rotation_matrix, translation_vector):
        self.rotation_matrix = rotation_matrix
        self.translation_vector = translation_vector

    def apply(self, vector):
        rotated = Vector(self.rotation_matrix[0][0] * vector.x + self.rotation_matrix[0][1] * vector.y + self.rotation_matrix[0][2] * vector.z, self.rotation_matrix[1][0] * vector.x + self.rotation_matrix[1][1] * vector.y + self.rotation_matrix[1][2] * vector.z, self.rotation_matrix[2][0] * vector.x + self.rotation_matrix[2][1] * vector.y + self.rotation_matrix[2][2] * vector.z)
        translated = rotated.add(self.translation_vector)
        return translated

class Processor:

    def __init__(self):
        self.transformations = []

    def add_transformation(self, transformation):
        self.transformations.append(transformation)

    def process(self, vector):
        for transformation in self.transformations:
            vector = transformation.apply(vector)
        return vector

def main():
    rotation_matrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]]
    translation_vector = Vector(1.0, 2.0, 3.0)
    transformation = Transformation(rotation_matrix, translation_vector)
    processor = Processor()
    processor.add_transformation(transformation)
    initial_vector = Vector(0.0, 0.0, 0.0)
    final_vector = processor.process(initial_vector)
    print(final_vector)
main()