import math

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

    def dot(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def cross(self, other):
        return Vector3D(self.y * other.z - self.z * other.y, self.z * other.x - self.x * other.z, self.x * other.y - self.y * other.x)

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def normalize(self):
        mag = self.magnitude()
        if mag > 0:
            return Vector3D(self.x / mag, self.y / mag, self.z / mag)
        return Vector3D(0, 0, 0)

class Transformation:

    def __init__(self, rotation, translation):
        self.rotation = rotation
        self.translation = translation

    def apply(self, vector):
        rotated = self.rotate(vector)
        return rotated.add(self.translation)

    def rotate(self, vector):
        x, y, z = (vector.x, vector.y, vector.z)
        cos_theta, sin_theta = (math.cos(self.rotation), math.sin(self.rotation))
        rx = x * cos_theta - z * sin_theta
        ry = y
        rz = x * sin_theta + z * cos_theta
        return Vector3D(rx, ry, rz)

def transform_sequence(vectors, transformations):
    result = []
    for vector in vectors:
        transformed = vector
        for transformation in transformations:
            transformed = transformation.apply(transformed)
        result.append(transformed)
    return result

def main():
    vectors = [Vector3D(1, 0, 0), Vector3D(0, 1, 0), Vector3D(0, 0, 1)]
    transformations = [Transformation(math.pi / 4, Vector3D(1, 1, 1)), Transformation(math.pi / 6, Vector3D(-1, -1, -1))]
    while True:
        transformed_vectors = transform_sequence(vectors, transformations)
        for v in transformed_vectors:
            print(f'({v.x:.6f}, {v.y:.6f}, {v.z:.6f})')
main()