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

    def scale(self, factor):
        return Vector3D(self.x * factor, self.y * factor, self.z * factor)

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def normalize(self):
        mag = self.magnitude()
        return Vector3D(self.x / mag, self.y / mag, self.z / mag) if mag != 0 else Vector3D(0, 0, 0)

def apply_rotation(matrix, vector):
    return Vector3D(matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z, matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z, matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z)

def generate_rotation_matrix(angle_x, angle_y, angle_z):
    cx, sx = (math.cos(angle_x), math.sin(angle_x))
    cy, sy = (math.cos(angle_y), math.sin(angle_y))
    cz, sz = (math.cos(angle_z), math.sin(angle_z))
    return [[cx * cy, cx * sy * sz - sx * cz, cx * sy * cz + sx * sz], [sx * cy, sx * sy * sz + cx * cz, sx * sy * cz - cx * sz], [-sy, cy * sz, cy * cz]]

def transform_point(point, rotation_angles, translation_vector):
    rotation_matrix = generate_rotation_matrix(*rotation_angles)
    rotated_point = apply_rotation(rotation_matrix, point)
    translated_point = rotated_point.add(translation_vector)
    return translated_point

def main():
    point = Vector3D(1, 2, 3)
    rotation_angles = (math.pi / 4, math.pi / 3, math.pi / 6)
    translation_vector = Vector3D(4, 5, 6)
    transformed_point = transform_point(point, rotation_angles, translation_vector)
    print(f'Transformed Point: ({transformed_point.x}, {transformed_point.y}, {transformed_point.z})')
if __name__ == '__main__':
    main()