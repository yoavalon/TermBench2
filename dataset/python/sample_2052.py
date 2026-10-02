class TransformationMatrix:

    def __init__(self, a, b, c, d, e, f, g, h, i):
        self.a, self.b, self.c = (a, b, c)
        self.d, self.e, self.f = (d, e, f)
        self.g, self.h, self.i = (g, h, i)

    def apply(self, x, y, z):
        new_x = self.a * x + self.b * y + self.c * z
        new_y = self.d * x + self.e * y + self.f * z
        new_z = self.g * x + self.h * y + self.i * z
        return (new_x, new_y, new_z)

class CoordinateTransformer:

    def __init__(self, matrix):
        self.matrix = matrix

    def transform_point(self, point):
        x, y, z = point
        return self.matrix.apply(x, y, z)

    def transform_points(self, points):
        return [self.transform_point(p) for p in points]

class GeometryAnalysis:

    def __init__(self, transformer):
        self.transformer = transformer

    def analyze(self, points):
        transformed_points = self.transformer.transform_points(points)
        results = []
        for point in transformed_points:
            results.append(self.calculate_distance(point))
        return results

    def calculate_distance(self, point):
        x, y, z = point
        return (x ** 2 + y ** 2 + z ** 2) ** 0.5

def main():
    matrix = TransformationMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1)
    transformer = CoordinateTransformer(matrix)
    analysis = GeometryAnalysis(transformer)
    points = [(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)]
    results = analysis.analyze(points)
    print(results)
if __name__ == '__main__':
    main()