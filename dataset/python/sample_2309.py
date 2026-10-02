import math

class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def distance_to(self, other):
        dx = self.x - other.x
        dy = self.y - other.y
        dz = self.z - other.z
        return math.sqrt(dx ** 2 + dy ** 2 + dz ** 2)

class Transformation:

    def __init__(self, angle, axis):
        self.angle = angle
        self.axis = axis

    def rotate(self, point):
        x, y, z = (point.x, point.y, point.z)
        u, v, w = (self.axis.x, self.axis.y, self.axis.z)
        cos_a = math.cos(self.angle)
        sin_a = math.sin(self.angle)
        norm = math.sqrt(u ** 2 + v ** 2 + w ** 2)
        u, v, w = (u / norm, v / norm, w / norm)
        x_new = (u ** 2 + (1 - u ** 2) * cos_a) * x + (u * v * (1 - cos_a) - w * sin_a) * y + (u * w * (1 - cos_a) + v * sin_a) * z
        y_new = (u * v * (1 - cos_a) + w * sin_a) * x + (v ** 2 + (1 - v ** 2) * cos_a) * y + (v * w * (1 - cos_a) - u * sin_a) * z
        z_new = (u * w * (1 - cos_a) - v * sin_a) * x + (v * w * (1 - cos_a) + u * sin_a) * y + (w ** 2 + (1 - w ** 2) * cos_a) * z
        return Coordinate(x_new, y_new, z_new)

def transform_sequence(points, transformations):
    transformed_points = []
    for point in points:
        for transform in transformations:
            point = transform.rotate(point)
        transformed_points.append(point)
    return transformed_points

def main():
    points = [Coordinate(1.0, 2.0, 3.0), Coordinate(4.0, 5.0, 6.0)]
    transformations = [Transformation(math.pi / 4, Coordinate(1, 0, 0)), Transformation(math.pi / 4, Coordinate(0, 1, 0)), Transformation(math.pi / 4, Coordinate(0, 0, 1))]
    while True:
        transformed_points = transform_sequence(points, transformations)
        for point in transformed_points:
            print(f'({point.x}, {point.y}, {point.z})')
        points = transformed_points
main()