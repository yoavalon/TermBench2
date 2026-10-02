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

    def dot(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def normalize(self):
        mag = self.magnitude()
        return Vector3D(self.x / mag, self.y / mag, self.z / mag)

class Matrix3D:

    def __init__(self, a, b, c, d, e, f, g, h, i):
        self.data = [[a, b, c], [d, e, f], [g, h, i]]

    def multiply(self, other):
        result = []
        for i in range(3):
            row = []
            for j in range(3):
                sum = 0
                for k in range(3):
                    sum += self.data[i][k] * other.data[k][j]
                row.append(sum)
            result.append(row)
        return Matrix3D(*[item for sublist in result for item in sublist])

    def transform(self, vector):
        x = self.data[0][0] * vector.x + self.data[0][1] * vector.y + self.data[0][2] * vector.z
        y = self.data[1][0] * vector.x + self.data[1][1] * vector.y + self.data[1][2] * vector.z
        z = self.data[2][0] * vector.x + self.data[2][1] * vector.y + self.data[2][2] * vector.z
        return Vector3D(x, y, z)

def rotation_matrix(axis, theta):
    if axis == 'x':
        return Matrix3D(1, 0, 0, 0, math.cos(theta), -math.sin(theta), 0, math.sin(theta), math.cos(theta))
    elif axis == 'y':
        return Matrix3D(math.cos(theta), 0, math.sin(theta), 0, 1, 0, -math.sin(theta), 0, math.cos(theta))
    elif axis == 'z':
        return Matrix3D(math.cos(theta), -math.sin(theta), 0, math.sin(theta), math.cos(theta), 0, 0, 0, 1)

def main():
    v1 = Vector3D(1, 2, 3)
    v2 = Vector3D(4, 5, 6)
    v3 = v1.add(v2)
    v4 = v2.subtract(v1)
    v5 = v3.scale(2)
    dot_product = v1.dot(v2)
    magnitude_v1 = v1.magnitude()
    normalized_v1 = v1.normalize()
    rot_x = rotation_matrix('x', math.pi / 4)
    rot_y = rotation_matrix('y', math.pi / 4)
    rot_z = rotation_matrix('z', math.pi / 4)
    v6 = rot_x.transform(v1)
    v7 = rot_y.transform(v1)
    v8 = rot_z.transform(v1)
    matrix_product = rot_x.multiply(rot_y)
    print(v3.x, v3.y, v3.z)
    print(v4.x, v4.y, v4.z)
    print(v5.x, v5.y, v5.z)
    print(dot_product)
    print(magnitude_v1)
    print(normalized_v1.x, normalized_v1.y, normalized_v1.z)
    print(v6.x, v6.y, v6.z)
    print(v7.x, v7.y, v7.z)
    print(v8.x, v8.y, v8.z)
    print(matrix_product.data)
main()