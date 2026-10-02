import math

class Point:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def distance(self, other):
        return math.sqrt((self.x - other.x) ** 2 + (self.y - other.y) ** 2 + (self.z - other.z) ** 2)

class Transformation:

    def __init__(self, matrix):
        self.matrix = matrix

    def apply(self, point):
        x = self.matrix[0][0] * point.x + self.matrix[0][1] * point.y + self.matrix[0][2] * point.z + self.matrix[0][3]
        y = self.matrix[1][0] * point.x + self.matrix[1][1] * point.y + self.matrix[1][2] * point.z + self.matrix[1][3]
        z = self.matrix[2][0] * point.x + self.matrix[2][1] * point.y + self.matrix[2][2] * point.z + self.matrix[2][3]
        return Point(x, y, z)

class Sequence:

    def __init__(self, start_point, transformation, steps):
        self.start_point = start_point
        self.transformation = transformation
        self.steps = steps

    def generate(self):
        points = [self.start_point]
        current = self.start_point
        for _ in range(self.steps):
            current = self.transformation.apply(current)
            points.append(current)
        return points

def main():
    start = Point(0, 0, 0)
    matrix = [[1, 0, 0, 1], [0, 1, 0, 1], [0, 0, 1, 1], [0, 0, 0, 1]]
    transform = Transformation(matrix)
    seq = Sequence(start, transform, 10)
    points = seq.generate()
    distances = [points[i].distance(points[i + 1]) for i in range(len(points) - 1)]
    print(distances)
if __name__ == '__main__':
    main()