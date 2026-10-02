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

    def magnitude(self):
        return (self.x ** 2 + self.y ** 2 + self.z ** 2) ** 0.5

class Transformation:

    def __init__(self, rotation_matrix, translation_vector):
        self.rotation_matrix = rotation_matrix
        self.translation_vector = translation_vector

    def apply(self, vector):
        x = vector.x * self.rotation_matrix[0][0] + vector.y * self.rotation_matrix[0][1] + vector.z * self.rotation_matrix[0][2]
        y = vector.x * self.rotation_matrix[1][0] + vector.y * self.rotation_matrix[1][1] + vector.z * self.rotation_matrix[1][2]
        z = vector.x * self.rotation_matrix[2][0] + vector.y * self.rotation_matrix[2][1] + vector.z * self.rotation_matrix[2][2]
        translated_vector = Vector3D(x, y, z).add(self.translation_vector)
        return translated_vector

def generate_sequence(start, transformation, steps):
    sequence = []
    current_vector = start
    for _ in range(steps):
        sequence.append(current_vector)
        current_vector = transformation.apply(current_vector)
    return sequence

def main():
    start_vector = Vector3D(1, 0, 0)
    rotation_matrix = [[0, -1, 0], [1, 0, 0], [0, 0, 1]]
    translation_vector = Vector3D(1, 1, 1)
    transformation = Transformation(rotation_matrix, translation_vector)
    sequence = generate_sequence(start_vector, transformation, 10)
    for vector in sequence:
        print(f'({vector.x}, {vector.y}, {vector.z})')
if __name__ == '__main__':
    main()