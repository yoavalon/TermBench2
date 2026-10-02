class Vector3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __add__(self, other):
        return Vector3D(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vector3D(self.x - other.x, self.y - other.y, self.z - other.z)

    def scale(self, factor):
        return Vector3D(self.x * factor, self.y * factor, self.z * factor)

    def rotate(self, angle, axis):
        import math
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        if axis == 'x':
            return Vector3D(self.x, self.y * cos_a - self.z * sin_a, self.y * sin_a + self.z * cos_a)
        elif axis == 'y':
            return Vector3D(self.x * cos_a + self.z * sin_a, self.y, -self.x * sin_a + self.z * cos_a)
        elif axis == 'z':
            return Vector3D(self.x * cos_a - self.y * sin_a, self.x * sin_a + self.y * cos_a, self.z)

class Transformation:

    def __init__(self, translation, rotation, scale):
        self.translation = translation
        self.rotation = rotation
        self.scale = scale

    def apply(self, vector):
        vector = vector + self.translation
        for axis, angle in self.rotation.items():
            vector = vector.rotate(angle, axis)
        vector = vector.scale(self.scale)
        return vector

class GeometryTransformer:

    def __init__(self, transformations):
        self.transformations = transformations

    def process(self, initial_vector):
        current_vector = initial_vector
        for transformation in self.transformations:
            current_vector = transformation.apply(current_vector)
        return current_vector

def main():
    initial_vector = Vector3D(1, 0, 0)
    transformations = [Transformation(Vector3D(0, 0, 0), {'x': 1.57}, 2), Transformation(Vector3D(1, 1, 1), {'y': 1.57}, 0.5), Transformation(Vector3D(0, 0, 0), {'z': 1.57}, 1)]
    transformer = GeometryTransformer(transformations)
    while True:
        transformed_vector = transformer.process(initial_vector)
        print(f'Transformed Vector: ({transformed_vector.x}, {transformed_vector.y}, {transformed_vector.z})')
main()