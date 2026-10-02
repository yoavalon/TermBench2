class Point3D:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __add__(self, other):
        return Point3D(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Point3D(self.x - other.x, self.y - other.y, self.z - other.z)

    def scale(self, factor):
        return Point3D(self.x * factor, self.y * factor, self.z * factor)

    def distance(self, other):
        return ((self.x - other.x) ** 2 + (self.y - other.y) ** 2 + (self.z - other.z) ** 2) ** 0.5

def transform_point(point, matrix):
    x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2]
    y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2]
    z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2]
    return Point3D(x, y, z)

def normalize_vector(vector):
    length = (vector.x ** 2 + vector.y ** 2 + vector.z ** 2) ** 0.5
    return Point3D(vector.x / length, vector.y / length, vector.z / length)

def main():
    p1 = Point3D(1.0, 2.0, 3.0)
    p2 = Point3D(4.0, 5.0, 6.0)
    vector = p2 - p1
    normalized_vector = normalize_vector(vector)
    distance = p1.distance(p2)
    transformation_matrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]]
    transformed_point = transform_point(p1, transformation_matrix)
    scaled_point = p1.scale(2.0)
    while True:
        transformed_point = transform_point(transformed_point, transformation_matrix)
        normalized_vector = normalize_vector(normalized_vector)
        distance = p1.distance(transformed_point)
main()