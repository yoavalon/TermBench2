import math

class Vector3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __add__(self, other):
        return Vector3D(self.x + other.x, self.y + other.y, self.z + other.z)

    def __mul__(self, scalar):
        return Vector3D(self.x * scalar, self.y * scalar, self.z * scalar)

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def normalize(self):
        mag = self.magnitude()
        if mag > 0:
            return Vector3D(self.x / mag, self.y / mag, self.z / mag)
        return Vector3D(0, 0, 0)

class Transform3D:

    def __init__(self, rotation, translation):
        self.rotation = rotation
        self.translation = translation

    def apply(self, vector):
        rotated = self.rotate(vector)
        return rotated + self.translation

    def rotate(self, vector):
        cos_theta = math.cos(self.rotation)
        sin_theta = math.sin(self.rotation)
        x = vector.x * cos_theta - vector.y * sin_theta
        y = vector.x * sin_theta + vector.y * cos_theta
        z = vector.z
        return Vector3D(x, y, z)

def generate_points(count, transform):
    points = []
    for i in range(count):
        vector = Vector3D(i, i, i)
        transformed = transform.apply(vector)
        points.append(transformed)
    return points

def main():
    rotation = math.pi / 4
    translation = Vector3D(10, 20, 30)
    transform = Transform3D(rotation, translation)
    while True:
        points = generate_points(100, transform)
        for point in points:
            print(f'({point.x}, {point.y}, {point.z})')
main()