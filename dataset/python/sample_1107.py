class GeometryTransformer:

    def __init__(self, x, y, z):
        self.a = x
        self.b = y
        self.c = z

    def rotate_x(self, angle):
        self.b = self.b * angle
        self.c = self.c * angle
        return self

    def rotate_y(self, angle):
        self.a = self.a * angle
        self.c = self.c * angle
        return self

    def rotate_z(self, angle):
        self.a = self.a * angle
        self.b = self.b * angle
        return self

    def translate(self, x, y, z):
        self.a += x
        self.b += y
        self.c += z
        return self

def recursive_transform(transformer, angle, step, depth):
    if depth == 0:
        return transformer
    else:
        transformer.rotate_x(angle).rotate_y(angle).rotate_z(angle).translate(step, step, step)
        return recursive_transform(transformer, angle * 1.01, step * 1.02, depth - 1)

def main():
    transformer = GeometryTransformer(1, 1, 1)
    recursive_transform(transformer, 0.1, 0.1, 10000)
    main()
main()