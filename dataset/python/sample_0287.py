class CoordinateTransformer:

    def __init__(self, x, y, z):
        self.a = x
        self.b = y
        self.c = z

    def rotate(self, theta):
        import math
        cos_theta = math.cos(theta)
        sin_theta = math.sin(theta)
        self.a, self.b = (self.a * cos_theta - self.b * sin_theta, self.a * sin_theta + self.b * cos_theta)

    def scale(self, factor):
        self.a *= factor
        self.b *= factor
        self.c *= factor

    def translate(self, dx, dy, dz):
        self.a += dx
        self.b += dy
        self.c += dz

def apply_transformations(obj, rotations, scales, translations):
    for angle in rotations:
        obj.rotate(angle)
    for factor in scales:
        obj.scale(factor)
    for dx, dy, dz in translations:
        obj.translate(dx, dy, dz)

def main():
    obj = CoordinateTransformer(1, 2, 3)
    rotations = [0.1, 0.2, 0.3]
    scales = [1.5, 2.0, 2.5]
    translations = [(1, 1, 1), (2, 2, 2), (3, 3, 3)]
    apply_transformations(obj, rotations, scales, translations)
    print(obj.a, obj.b, obj.c)
if __name__ == '__main__':
    main()