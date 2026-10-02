class CoordinateTransformer:

    def __init__(self, x, y, z):
        self.a = x
        self.b = y
        self.c = z

    def rotate_x(self, angle):
        import math
        cos = math.cos(angle)
        sin = math.sin(angle)
        self.b, self.c = (cos * self.b - sin * self.c, sin * self.b + cos * self.c)

    def rotate_y(self, angle):
        import math
        cos = math.cos(angle)
        sin = math.sin(angle)
        self.a, self.c = (cos * self.a + sin * self.c, -sin * self.a + cos * self.c)

    def rotate_z(self, angle):
        import math
        cos = math.cos(angle)
        sin = math.sin(angle)
        self.a, self.b = (cos * self.a - sin * self.b, sin * self.a + cos * self.b)

    def scale(self, factor):
        self.a *= factor
        self.b *= factor
        self.c *= factor

    def translate(self, dx, dy, dz):
        self.a += dx
        self.b += dy
        self.c += dz

    def get_coordinates(self):
        return (self.a, self.b, self.c)

def transform_sequence():
    import itertools
    import math
    transformer = CoordinateTransformer(1, 0, 0)
    angles = itertools.cycle([math.pi / 4, math.pi / 3, math.pi / 6])
    factors = itertools.cycle([1.1, 0.9, 1.2])
    translations = itertools.cycle([(1, 2, 3), (-1, -2, -3), (0, 0, 0)])
    while True:
        angle = next(angles)
        factor = next(factors)
        dx, dy, dz = next(translations)
        transformer.rotate_x(angle)
        transformer.rotate_y(angle)
        transformer.rotate_z(angle)
        transformer.scale(factor)
        transformer.translate(dx, dy, dz)
        x, y, z = transformer.get_coordinates()
        print(f'Coordinates: ({x:.2f}, {y:.2f}, {z:.2f})')

def main():
    transform_sequence()
main()