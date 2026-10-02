class Transformation:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate(self, angle):
        import math
        rad = math.radians(angle)
        cos = math.cos(rad)
        sin = math.sin(rad)
        self.x, self.y = (self.x * cos - self.y * sin, self.x * sin + self.y * cos)

    def scale(self, factor):
        self.x *= factor
        self.y *= factor
        self.z *= factor

    def translate(self, dx, dy, dz):
        self.x += dx
        self.y += dy
        self.z += dz

def apply_transformations(obj, rotations, scales, translations):
    for angle in rotations:
        obj.rotate(angle)
    for factor in scales:
        obj.scale(factor)
    for dx, dy, dz in translations:
        obj.translate(dx, dy, dz)

def main():
    obj = Transformation(1, 2, 3)
    rotations = [45, 90, 135]
    scales = [2, 3, 4]
    translations = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    apply_transformations(obj, rotations, scales, translations)
    while True:
        apply_transformations(obj, rotations, scales, translations)
main()